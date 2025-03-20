#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <unistd.h>

// Définition des broches du PmodSSD (port JA sur PmodHAT)
#define SSD_A  26
#define SSD_B  13
#define SSD_C  3
#define SSD_D  2
#define SSD_E  7
#define SSD_F  10
#define SSD_G  9
#define SELECT_DISPLAY 11  // Sélection de l'afficheur (0 = gauche, 1 = droit)

// Tableau des broches associées aux segments
const int SSD_PINS[7] = {SSD_A, SSD_B, SSD_C, SSD_D, SSD_E, SSD_F, SSD_G};

// Table de correspondance des chiffres 0-9 en segments
const int digits[10][7] = {
    {1,1,1,1,1,1,0},  // 0
    {0,1,1,0,0,0,0},  // 1
    {1,1,0,1,1,0,1},  // 2
    {1,1,1,1,0,0,1},  // 3
    {0,1,1,0,0,1,1},  // 4
    {1,0,1,1,0,1,1},  // 5
    {1,0,1,1,1,1,1},  // 6
    {1,1,1,0,0,0,0},  // 7
    {1,1,1,1,1,1,1},  // 8
    {1,1,1,0,0,1,1}   // 9
};

// Fonction d'affichage d'un chiffre sur l'afficheur sélectionné
void displayDigit(int num, int position) {
    if (num < 0 || num > 9) {
        printf("Erreur : Valeur non valide\n");
        return;
    }

    // Sélectionner l'afficheur (0 = gauche, 1 = droit)
    digitalWrite(SELECT_DISPLAY, position);

    // Activer les segments pour afficher le chiffre
    for (int i = 0; i < 7; i++) {
        digitalWrite(SSD_PINS[i], digits[num][i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage : %s <valeur> <position> <durée>\n", argv[0]);
        return 1;
    }

    int value = atoi(argv[1]);  // Valeur à afficher (0-9)
    int position = atoi(argv[2]); // Position de l'afficheur (0 = gauche, 1 = droit)
    int duration = atoi(argv[3]); // Durée d'affichage (secondes)

    if (value < 0 || value > 9) {
        printf("Erreur : La valeur doit être comprise entre 0 et 9\n");
        return 1;
    }
    if (position < 0 || position > 1) {
        printf("Erreur : La position doit être 0 (gauche) ou 1 (droit)\n");
        return 1;
    }

    // Initialisation de wiringPi en mode GPIO standard
    if (wiringPiSetupGpio() == -1) {
        printf("Erreur d'initialisation de wiringPi\n");
        return 1;
    }

    // Configurer les broches comme sorties
    for (int i = 0; i < 7; i++) {
        pinMode(SSD_PINS[i], OUTPUT);
    }
    pinMode(SELECT_DISPLAY, OUTPUT);  // Configurer la sélection d'afficheur

    // Afficher le chiffre sur l'afficheur sélectionné
    displayDigit(value, position);

    // Attente avant d'éteindre l'afficheur
    sleep(duration);

    // Éteindre l'afficheur
    for (int i = 0; i < 7; i++) {
        digitalWrite(SSD_PINS[i], 0);
    }

    return 0;
}
