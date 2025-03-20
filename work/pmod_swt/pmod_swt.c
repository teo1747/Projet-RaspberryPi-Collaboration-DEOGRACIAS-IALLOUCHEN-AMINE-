#include "/home/mi005558/pi/work/common/common.h"
#include "/home/mi005558/pi/work/gpio/gpio.h"
#include <stdio.h>
#include <stdlib.h>

#define count 8

int main(int argc, char *argv[]) {
    // Vérifie que le port GPIO est spécifié en argument
    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Définit une variable pour le port GPIO spécifié
    char *Port = argv[1];
    char* J;
	
	// Assigne le tableau de broches correspondant au port GPIO spécifié
    if(Port[0] == 'a'){
        J = JA;
    }else if(Port[0] == 'b'){
        J = JB;
    }else if(Port[0] == 'c'){
        J = JC;
    }else{
        // Affiche une erreur si le port n'est pas reconnu
        fprintf(stderr, "le port est introuvable : %c\n", Port[0]);
        return 1;
    }

    int val = 0;
    int bcount = 0;

    // Parcourt les broches du port GPIO et récupère leur état
    for (int i = 0; i < count; i++) {
        gpio_set_direction(J[i], 0);
        int Bit = gpio_get_value(J[i]);

        // Ajoute le bit récupéré à la valeur totale
        val += Bit * (1 << bcount);
        printf("%d : %d\n", J[i], Bit);
        bcount++;
    }

    // Affiche la valeur récupérée en format hexadécimal
    printf("%x\n", val);

    return 0;
}
