#include "/home/mi005558/pi/work/common/common.h"
#include "/home/mi005558/pi/work/gpio/gpio.h"

#define NUM_LEDS 8

int main()
{
    // Définition des broches utilisées pour les LEDS
    int led_pins[NUM_LEDS] = {8, 10, 9, 11, 19, 21, 20, 18};

    // Configuration des broches en sortie pour les LEDS
    for (int i = 0; i < NUM_LEDS; i++) {
        gpio_set_direction(led_pins[i], 1);
    }

    // Boucle principale du programme
    int binary_count = 0;
    while (1) {
        binary_count++;

        // Mise à jour de l'état des LEDS en fonction du compteur binaire
        for (int i = 0; i < NUM_LEDS; i++) {
            int output_bit = (binary_count >> i) & 1;
            gpio_set_value(led_pins[i], output_bit);
        }

        usleep(100000); // Pause de 100ms
    }

    return 0;
}

