from gpio import *   # Importe tous les éléments de la bibliothèque gpio
import sys          # Importe le module sys pour gérer les arguments en ligne de commande

NB_PINS = 8         # Définit le nombre de broches à lire

if len(sys.argv) < 2:   # Si aucun argument en ligne de commande n'a été fourni
    print(f"Usage: {sys.argv[0]} <port>")   # Affiche un message d'erreur avec le nom du script
    sys.exit(1)         # Arrête le script avec un code d'erreur

port = sys.argv[1]  # Récupère le premier argument en ligne de commande
if port == 'a':     # Si le port spécifié est 'a'
    pin_list = JA   # Utilise la liste de broches PA
elif port == 'b':   # Sinon, si le port spécifié est 'b'
    pin_list = JB   # Utilise la liste de broches PB
elif port == 'c':   # Sinon, si le port spécifié est 'c'
    pin_list = JC   # Utilise la liste de broches PC
else:               # Sinon, si le port spécifié n'est ni 'a', ni 'b', ni 'c'
    print(f"Port inconnu : {port}")    # Affiche un message d'erreur
    sys.exit(1)         # Arrête le script avec un code d'erreur

val = 0           # Initialise la variable qui stockera la valeur binaire lue
bit_count = 0       # Initialise le compteur de bits lus

for i in range(NB_PINS):    # Boucle sur toutes les broches à lire
    gpio_set_direction(pin_list[i], 0)   # Configure la broche en entrée
    bit = gpio_get_value(pin_list[i])    # Lit la valeur de la broche
    val += bit * (1 << bit_count)      # Convertit la valeur lue en nombre binaire
    print(f"{pin_list[i]} : {bit}")     # Affiche la valeur lue pour la broche
    bit_count += 1      # Incrémente le compteur de bits lus

print(f"{val:x}") 
