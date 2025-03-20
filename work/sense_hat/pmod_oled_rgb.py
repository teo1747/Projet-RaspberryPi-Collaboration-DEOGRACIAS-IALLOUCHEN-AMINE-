from DesignSpark.Pmod.HAT import createPmod
import time

try:
    # Initialisation de l'écran OLED
    oled = createPmod('OLEDrgb', 'JA')
    device = oled.getDevice()  # Vérifier si le port est correctement configuré

    # Effacer l'écran
    oled.clear()

    # Dessiner un rectangle et afficher un message
    oled.draw_filled_rectangle(0, 0, 95, 63, PmodOLEDrgb.Color.BLUE)
    oled.draw_text(10, 20, "Hello!", PmodOLEDrgb.Color.YELLOW)

    # Rafraîchir l'écran
    oled.display()

except Exception as e:
    print(f"Erreur : {e}")

