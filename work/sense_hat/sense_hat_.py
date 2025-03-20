from sense_hat import SenseHat

# Initialisation du Sense HAT
sense = SenseHat()

# Lecture des capteurs
temperature = sense.get_temperature()
humidity = sense.get_humidity()
pressure = sense.get_pressure()

# Affichage des valeurs dans le terminal
print(f"Température : {temperature:.2f} °C")
print(f"Humidité : {humidity:.2f} %")
print(f"Pression : {pressure:.2f} hPa")

