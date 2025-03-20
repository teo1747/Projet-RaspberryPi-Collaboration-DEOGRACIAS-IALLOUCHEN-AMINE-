#!/bin/bash

# Crée le fichier s'il n'existe pas déjà (optionnel si déjà créé)
touch /home/esirem/dates.log

# Ajoute un message de début dans le fichier (optionnel)
echo "Début des enregistrements" > /home/esirem/dates.log

# Boucle pour enregistrer la date toutes les 30 secondes
while true; do
    echo "$(date)" >> /home/esirem/dates.log
    sleep 30
done


