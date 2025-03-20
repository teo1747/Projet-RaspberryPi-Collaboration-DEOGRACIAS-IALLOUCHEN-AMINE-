#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Pour usleep()

#define GPIO_EXPORT_PATH "/sys/class/gpio/export"
#define GPIO_DIRECTION_PATH_TEMPLATE "/sys/class/gpio/gpio%d/direction"
#define GPIO_VALUE_PATH_TEMPLATE "/sys/class/gpio/gpio%d/value"

// Vérifie si un GPIO est déjà exporté
int gpio_is_exported(int pin) {
    char path[256];
    sprintf(path, GPIO_VALUE_PATH_TEMPLATE, pin);
    FILE *file = fopen(path, "r");
    if (file) {
        fclose(file);
        return 1; // GPIO déjà exporté
    }
    return 0; // GPIO non exporté
}

// Exporte un GPIO si nécessaire
void gpio_export(int pin) {
    if (!gpio_is_exported(pin)) {
        FILE *export_file = fopen(GPIO_EXPORT_PATH, "w");
        if (!export_file) {
            perror("Erreur lors de l'export du GPIO");
            return;
        }
        fprintf(export_file, "%d", pin);
        fclose(export_file);
        
        // Attendre la création des fichiers GPIO
        usleep(100000); 
    }
}

// Définit la direction du GPIO
void gpio_set_direction(int pin, int direction) {
    gpio_export(pin); // S'assurer que le GPIO est exporté

    char direction_path[256];
    sprintf(direction_path, GPIO_DIRECTION_PATH_TEMPLATE, pin);
    FILE *direction_file = fopen(direction_path, "w");
    if (!direction_file) {
        perror("Erreur lors de l'ouverture du fichier direction");
        return;
    }

    fprintf(direction_file, "%s", direction ? "out" : "in"); // Correction ici
    fclose(direction_file);
}

// Écrit une valeur sur le GPIO
void gpio_set_value(int pin, int value) {
    char value_path[256];
    sprintf(value_path, GPIO_VALUE_PATH_TEMPLATE, pin);
    FILE *value_file = fopen(value_path, "w");
    if (!value_file) {
        perror("Erreur lors de l'ouverture du fichier value");
        return;
    }
    fprintf(value_file, "%d", value);
    fclose(value_file);
}

// Lit une valeur du GPIO
int gpio_get_value(int pin) {
    char value_path[256];
    sprintf(value_path, GPIO_VALUE_PATH_TEMPLATE, pin);
    FILE *value_file = fopen(value_path, "r");
    if (!value_file) {
        perror("Erreur lors de la lecture du fichier value");
        return -1;
    }
    int value;
    if (fscanf(value_file, "%d", &value) != 1) { // Vérifier fscanf()
        perror("Erreur lors de la lecture de la valeur du GPIO");
        fclose(value_file);
        return -1;
    }
    fclose(value_file);
    return value;
}
