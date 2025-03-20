#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

#define I2C_ADDR 0x40  // Adresse I2C du PmodHYGRO

int main() {
    int file;
    char *i2c_device = "/dev/i2c-1";

    // Ouvrir le bus I2C
    if ((file = open(i2c_device, O_RDWR)) < 0) {
        perror("Erreur lors de l'ouverture du bus I2C");
        return 1;
    }

    // Sélectionner le périphérique I2C
    if (ioctl(file, I2C_SLAVE, I2C_ADDR) < 0) {
        perror("Erreur lors de la sélection du périphérique I2C");
        close(file);
        return 1;
    }

    // Lecture de l'identifiant produit et vendeur
    char reg = 0xFC;  // Registre ID
    char buf[2];

    if (write(file, &reg, 1) != 1) {
        perror("Erreur lors de l'écriture du registre ID");
    }
    if (read(file, buf, 2) != 2) {
        perror("Erreur lors de la lecture de l'ID");
    } else {
        printf("Identifiant produit: 0x%X\n", buf[0]);
        printf("Identifiant vendeur: 0x%X\n", buf[1]);
    }

    // Lecture de la température
    reg = 0xE3; // Commande pour lire la température
    if (write(file, &reg, 1) != 1) {
        perror("Erreur lors de l'écriture du registre Température");
    }
    if (read(file, buf, 2) != 2) {
        perror("Erreur lors de la lecture de la Température");
    } else {
        int temp_raw = (buf[0] << 8) | buf[1];
        float temperature = ((temp_raw * 175.72) / 65536.0) - 46.85;
        printf("Température : %.2f°C\n", temperature);
    }

    // Lecture de l'humidité
    reg = 0xE5; // Commande pour lire l'humidité
    if (write(file, &reg, 1) != 1) {
        perror("Erreur lors de l'écriture du registre Humidité");
    }
    if (read(file, buf, 2) != 2) {
        perror("Erreur lors de la lecture de l'Humidité");
    } else {
        int hum_raw = (buf[0] << 8) | buf[1];
        float humidity = ((hum_raw * 125.0) / 65536.0) - 6.0;
        printf("Humidité : %.2f%%\n", humidity);
    }

    // Fermer le fichier I2C
    close(file);

    return 0;
}
