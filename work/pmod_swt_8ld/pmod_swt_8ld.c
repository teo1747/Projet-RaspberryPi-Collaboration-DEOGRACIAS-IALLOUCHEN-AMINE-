#include <stdio.h>
#include <stdlib.h>
#include "/home/mi005558/pi/work/common/common.h"
#include "/home/mi005558/pi/work/gpio/gpio.h"

#define COUNT 8

int main() {
    char *SWT = JB; // Tableau des broches des interrupteurs
    char *LED = JC; // Tableau des broches des LEDs

    // Configurer les interrupteurs en entrée et les LEDs en sortie
    for (int i = 0; i < COUNT; i++) {
        gpio_set_direction(SWT[i], 0); // Configurer interrupteurs en entrée
        gpio_set_direction(LED[i], 1); // Configurer LEDs en sortie
    }

    while (1) {
        for (int i = 0; i < COUNT; i++) {
            int state = gpio_get_value(SWT[i]); // Lire l'état des interrupteurs
            if (state != -1) { // Vérification d'erreur
                gpio_set_value(LED[i], state); // Afficher sur les LEDs
            }
        }
    }

    return 0;
}
