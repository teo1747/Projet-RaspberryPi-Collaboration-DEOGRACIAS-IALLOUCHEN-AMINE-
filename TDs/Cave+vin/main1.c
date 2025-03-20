#include <stdio.h>
#include "vin.h"
#include "cave.h"

int main() {
    cave ma_cave = { .compteur = 0 };

    printf("Saisie du premier vin :\n");
    saisie_vin_cave(&ma_cave);

    printf("Saisie du deuxième vin :\n");
    saisie_vin_cave(&ma_cave);

    printf("\nCave actuelle :\n");
    affiche_cave(ma_cave);

    int annee_recherchee = 2005;
    printf("\nAffichage des vins de l'année %d :\n", annee_recherchee);
    affiche_cave_annee(ma_cave, annee_recherchee);

    printf("\nBoire du vin :\n");
    boire(&ma_cave);

    printf("\nCave après avoir bu des bouteilles :\n");
    affiche_cave(ma_cave);

    printf("\nSuppression d'un vin de la cave :\n");
    int vin_a_supprimer;
    printf("Entrez le numéro du vin à supprimer : ");
    scanf("%d", &vin_a_supprimer);
    supprimer_vin(&ma_cave, vin_a_supprimer);

    printf("\nCave après suppression :\n");
    affiche_cave(ma_cave);

    return 0;
}

