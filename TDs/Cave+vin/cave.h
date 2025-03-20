#ifndef CAVE_H
#define CAVE_H

#include "vin.h"

#define MAX_VINS 50

typedef struct {
    vin vins[MAX_VINS];
    int compteur;
} cave;

void saisie_vin(vin *a);  // Déclaration de la fonction saisie_vin
void saisie_vin_cave(cave *une_cave);  // Déclaration de la fonction saisie_vin_cave
void affiche_cave(cave une_cave);  // Déclaration de la fonction affiche_cave
void affiche_cave_annee(cave une_cave, int annee);  // Déclaration de la fonction affiche_cave_annee
void boire(cave *une_cave);  // Déclaration de la fonction boire
void supprimer_vin(cave *une_cave, int num);  // Déclaration de la fonction supprimer_vin

#endif




