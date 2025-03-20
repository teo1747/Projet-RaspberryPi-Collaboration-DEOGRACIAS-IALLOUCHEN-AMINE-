from sense_hat import SenseHat
import time

sense = SenseHat()
sense.clear()  # Nettoie l'affichage

while True:
    temp = sense.get_temperature()
    humidity = sense.get_humidity()
    pressure = sense.get_pressure()

    msg = f"T:{temp:.1f}C H:{humidity:.1f}% P:{pressure:.1f}hPa"
    
    sense.show_message(msg, scroll_speed=0.05, text_colour=[255, 255, 255])

    time.sleep(2)  # Pause avant la prochaine mise à jour
