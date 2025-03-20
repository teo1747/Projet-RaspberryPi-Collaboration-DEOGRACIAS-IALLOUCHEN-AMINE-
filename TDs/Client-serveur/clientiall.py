import socket

# Créer un objet socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Se connecter au serveur
server_address = ("10.169.197.58" , 12345)  # Remplacez <adresse_ip_du_serveur> par l'IP du serveur
client_socket.connect(server_address)

# Entrer un message à envoyer
message = input("Entrez le message à envoyer : ")

# Envoyer le message au serveur
client_socket.send(message.encode('utf-8'))

# Fermer la connexion
client_socket.close()

