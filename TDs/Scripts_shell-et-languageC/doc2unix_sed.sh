#!/bin/bash

[ -f "$1" ] || { echo "Usage: $0 <fichier_existant>"; exit 1; }

sed -i 's/\r//g' "$1"
echo "Conversion terminée : '$1' au format Unix."
