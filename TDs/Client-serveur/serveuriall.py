import socket

# Créer un objet socket
serveur_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Lier le socket à une adresse (adresse IP de l'ordinateur et port)
serveur_socket.bind(('0.0.0.0', 12345)) 
serveur_socket.listen(1)

print("Serveur en attente de connexion...")
# Accepter la connexion d'un client
connexion, adresse = serveur_socket.accept()
print(f"Connexion établie avec {adresse}")

# Recevoir la chaîne de caractères envoyée par le client
message = connexion.recv(1024).decode('utf-8')  # 1024 octets maximum
print(f"Message reçu : {message}")

# Fermer la connexion
connexion.close()
serveur_socket.close()
