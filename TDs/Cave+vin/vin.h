#ifndef VIN_H
#define VIN_H

#define MAX_NOM 100
#define MAX_TYPE 50

typedef struct {
    char nom[MAX_NOM];           // Nom du vin
    char type[MAX_TYPE];         // Type du vin (ex: rouge, blanc, etc.)
    int annee;                   // Année du vin
    int nb_bouteilles;           // Nombre de bouteilles dans la cave
} vin;

#endif


