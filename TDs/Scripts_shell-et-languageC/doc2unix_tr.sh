#!/bin/bash

[ -f "$1" ] || { echo "Usage: $0 <fichier_existant>"; exit 1; }

tr -d '\r' < "$1" > fichier10.txt
echo "Conversion terminée : '$1' au format Unix."
