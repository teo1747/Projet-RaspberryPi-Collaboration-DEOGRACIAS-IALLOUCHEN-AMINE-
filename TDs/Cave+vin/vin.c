#include <stdio.h>
#include "vin.h"

void saisie_vin(vin *a) {
    printf("Entrez le nom du vin : ");
    scanf("%s", a->nom);  // Saisie du nom du vin

    printf("Entrez le type de vin (rouge, blanc, etc.) : ");
    scanf("%s", a->type);  // Saisie du type de vin

    printf("Entrez l'année du vin : ");
    scanf("%d", &a->annee);  // Saisie de l'année

    printf("Entrez le nombre de bouteilles : ");
    scanf("%d", &a->nb_bouteilles);  // Saisie du nombre de bouteilles
}

