import RPi.GPIO as GPIO
GPIO.setwarnings(False)
from DesignSpark.Pmod.HAT import createPmod
from luma.core.render import canvas
from luma.oled.device import ssd1331
import time
if __name__ == '__main__':
    try:
        # Initialisation de l'écran OLED
        oled = createPmod('OLEDrgb', 'JB')
        device = oled.getDevice()  # Vérifier si le port est correctement configuré

        # Effacer l'écran (remplacer par la bonne méthode si nécessaire)
        device.clear()

        # Dessiner un rectangle et afficher un message
        with canvas(device) as draw:
            draw.rectangle(device.bounding_box, outline="green", fill="black")
            draw.text((15, 10), "Capteur t/h", fill="green")

        # Rafraîchir l'écran
        

        # Laisser le message affiché quelques secondes
        time.sleep(10)

        # Nettoyage des ressources
        oled.cleanup()

    except Exception as e:
        print(f"Erreur : {e}")
								
