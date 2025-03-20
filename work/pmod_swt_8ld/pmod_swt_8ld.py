import time
import sys
from gpio import JB, JC, gpio_set_direction, gpio_get_value, gpio_set_value

# Configuration des broches en entrée (interrupteurs) et en sortie (LEDs)
for i in range(8):
    gpio_set_direction(JB[i], 0)  # Configurer les interrupteurs en entrée
    gpio_set_direction(JC[i], 1)  # Configurer les LEDs en sortie

while True:
    val = 0
    for i in range(8):
        bit = gpio_get_value(JB[i])  # Lire l'état des interrupteurs
        gpio_set_value(JC[i], bit)   # Mettre à jour les LEDs en fonction des interrupteurs
        val += bit * (1 << i)
    
    print(f"Valeur lue : {val:08b}")  # Affiche la valeur binaire lue
    time.sleep(0.5)  # Pause pour éviter une lecture trop rapide
