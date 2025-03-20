#include <stdio.h>
#include "cave.h"

void saisie_vin_cave(cave *une_cave) {
    if (une_cave->compteur < MAX_VINS) {
        saisie_vin(&une_cave->vins[une_cave->compteur]);  // Saisie d'un vin
        une_cave->compteur++;  // Incrémentation du compteur de vins dans la cave
    } else {
        printf("La cave est pleine !\n");
    }
}
void affiche_cave(cave une_cave) {
    if (une_cave.compteur == 0) {
        printf("La cave est vide.\n");
    } else {
        for (int i = 0; i < une_cave.compteur; i++) {
            printf("Case %d : %s %s %d %d bouteilles\n", 
                    i, une_cave.vins[i].nom, une_cave.vins[i].type, 
                    une_cave.vins[i].annee, une_cave.vins[i].nb_bouteilles);
        }
    }
}
void affiche_cave_annee(cave une_cave, int annee) {
    int trouve = 0;
    for (int i = 0; i < une_cave.compteur; i++) {
        if (une_cave.vins[i].annee == annee) {
            printf("Case %d : %s %s %d %d bouteilles\n", 
                    i, une_cave.vins[i].nom, une_cave.vins[i].type, 
                    une_cave.vins[i].annee, une_cave.vins[i].nb_bouteilles);
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucun vin trouvé pour l'année %d.\n", annee);
    }
}
void supprimer_vin(cave *une_cave, int num) {
    if (num >= 0 && num < une_cave->compteur) {
        for (int i = num; i < une_cave->compteur - 1; i++) {
            une_cave->vins[i] = une_cave->vins[i + 1];  // Décalage des vins
        }
        une_cave->compteur--;  // Mise à jour du compteur
        printf("Vin supprimé avec succès.\n");
    } else {
        printf("Numéro de case invalide.\n");
    }
}
void boire(cave *une_cave) {
    int num, nb_bouteilles;
    
    affiche_cave(*une_cave);  // Affichage de la cave pour que l'utilisateur choisisse un vin
    printf("Entrez le numéro du vin que vous voulez boire : ");
    scanf("%d", &num);

    if (num >= 0 && num < une_cave->compteur) {
        printf("Entrez le nombre de bouteilles à boire : ");
        scanf("%d", &nb_bouteilles);

        if (une_cave->vins[num].nb_bouteilles >= nb_bouteilles) {
            une_cave->vins[num].nb_bouteilles -= nb_bouteilles;
            printf("Il reste %d bouteilles de %s %s %d.\n", 
                   une_cave->vins[num].nb_bouteilles, 
                   une_cave->vins[num].nom, une_cave->vins[num].type, 
                   une_cave->vins[num].annee);

            if (une_cave->vins[num].nb_bouteilles == 0) {
                supprimer_vin(une_cave, num);  // Suppression du vin si plus de bouteilles
            }
        } else {
            printf("Pas assez de bouteilles dans la cave.\n");
        }
    } else {
        printf("Numéro de vin invalide.\n");
    }
}
