from pmodhygro import PmodHygro
import time

# Initialisation du capteur
sensor = PmodHygro()

# Démarrage de l'I2C
sensor.begin_i2c()

# Boucle pour lire les données du capteur
while True:
    try:
        # Lecture de la température et de l'humidité
        temp = sensor.get_temperature()  # en °C
        temp_f = sensor.get_temperature_f()  # en °F
        hum = sensor.get_humidity()  # en %

        # Affichage des valeurs lues
        print(f"Temperature: {temp:.2f} °C / {temp_f:.2f} °F")
        print(f"Humidite: {hum:.2f} %")

        # Attendre avant la prochaine lecture (par exemple 2 secondes)
        time.sleep(2)

    except Exception as e:
        print(f"Erreur lors de la lecture du capteur : {e}")
        time.sleep(2)

