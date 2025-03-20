import spidev
# Déclaration des constantes pour le bus SPI
SPIDEVICE = "/dev/spidev0.0"
SPIMODE = 3
SPIBITS = 8
SPISPEED = 2000000
# Commande pour lire la valeur de la lumière
CMDREAD = 0x12
# Initialisation du bus SPI
spi = spidev.SpiDev()
spi.open(0, 0)
spi.max_speed_hz = SPISPEED
spi.mode = SPIMODE
spi.bits_per_word = SPIBITS
# Envoi de la commande de lecture et récupération de la valeur de la lumière
buff1 = [CMDREAD, 0x00]
buff2 = spi.xfer2(buff1)
# Conversion des octets reçus en valeur numérique de la lumière
lightvalue = (buff2[0] << 8) | buff2[1]
# Affichage de la valeur de la lumière
print("La valeur de la lumière est de : {}".format(lightvalue))
# Fermeture du bus SPI
spi.close()
