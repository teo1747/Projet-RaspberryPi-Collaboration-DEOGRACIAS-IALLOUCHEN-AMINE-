#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

#define SPI_DEVICE "/dev/spidev0.0"
#define SPI_MODE SPI_MODE_3
#define SPI_BITS_PER_WORD 8
#define SPI_SPEED_HZ 2000000

#define PmodALS_CMD_READ 0x12  // Commande de lecture pour le capteur de lumière PmodALS

int main()
{
    // Ouvre le périphérique SPI
    int spi_fd = open(SPI_DEVICE, O_RDWR);
    if (spi_fd < 0)
    {
        perror("Impossible d'ouvrir le périphérique SPI");
        return 1;
    }

    // Configure le mode SPI
    uint8_t spi_mode = SPI_MODE;
    if (ioctl(spi_fd, SPI_IOC_WR_MODE, &spi_mode) < 0)
    {
        perror("Impossible de configurer le mode SPI");
        close(spi_fd);
        return 1;
    }

    // Configure le nombre de bits par mot
    uint8_t spi_bits_per_word = SPI_BITS_PER_WORD;
    if (ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &spi_bits_per_word) < 0)
    {
        perror("Impossible de configurer le nombre de bits par mot SPI");
        close(spi_fd);
        return 1;
    }

    // Configure la vitesse SPI
    uint32_t spi_speed_hz = SPI_SPEED_HZ;
    if (ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &spi_speed_hz) < 0)
    {
        perror("Impossible de configurer la vitesse SPI");
        close(spi_fd);
        return 1;
    }

    // Buffers de transmission et réception
    uint8_t tx_buffer[2] = {PmodALS_CMD_READ, 0x00}; // Commande + octet vide
    uint8_t rx_buffer[2] = {0x00, 0x00}; // Buffer de réception

    // Structure de transfert SPI
    struct spi_ioc_transfer transfer =
    {
        .tx_buf = (unsigned long)tx_buffer,
        .rx_buf = (unsigned long)rx_buffer,
        .len = 2,  // Taille du transfert en octets
        .speed_hz = spi_speed_hz,
        .bits_per_word = spi_bits_per_word,
        .delay_usecs = 0,
    };

    // Envoie la commande et reçoit la réponse
    if (ioctl(spi_fd, SPI_IOC_MESSAGE(1), &transfer) < 0)
    {
        perror("Erreur lors de la communication SPI");
        close(spi_fd);
        return 1;
    }

    // Interprète la valeur de lumière
    uint16_t light = (rx_buffer[0] << 8) | rx_buffer[1];

    // Affiche la valeur lue
    printf("Valeur de lumière : %u\n", light);

    // Ferme le périphérique SPI
    close(spi_fd);

    return 0;
}
