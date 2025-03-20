# Importer les fonctions nécessaires de gpio.py et time.py
from gpio import JA, JB, JC, gpio_set_direction, gpio_set_value
import time

# Définir le nombre de LEDs connectées et allumer leur direction sur "sortie"
num_leds = 8
for pin in JA:
    gpio_set_direction(pin, 1)

# Initialiser le compteur des LEDs allumées
led_count = 0

# Boucle infinie pour allumer progressivement les LEDs
while True:
    led_count += 1  # Incrémenter le compteur des LEDs allumées
    for i in range(num_leds):
        output_bit = (led_count >> i) & 1  # Récupérer le bit correspondant à l'indice i dans le compteur
        gpio_set_value(JA[i], output_bit)  # Allumer ou éteindre la LED correspondante en fonction du bit
    time.sleep(0.1)  # Attendre un petit moment avant de continuer
