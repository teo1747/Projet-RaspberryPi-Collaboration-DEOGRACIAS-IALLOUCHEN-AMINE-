#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <pthread.h>
#include <unistd.h>

#define SSD_A  26
#define SSD_B  13
#define SSD_C  3
#define SSD_D  2
#define SSD_E  7
#define SSD_F  10
#define SSD_G  9
#define SELECT_DISPLAY 11  // Sélection de l'afficheur (0 = gauche, 1 = droit)

const int SSD_PINS[7] = {SSD_A, SSD_B, SSD_C, SSD_D, SSD_E, SSD_F, SSD_G};
const int digits[10][7] = {
    {1,1,1,1,1,1,0},  {0,1,1,0,0,0,0},
    {1,1,0,1,1,0,1},  {1,1,1,1,0,0,1},
    {0,1,1,0,0,1,1},  {1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1},  {1,1,1,0,0,0,0},
    {1,1,1,1,1,1,1},  {1,1,1,0,0,1,1}
};

int max_value = 99;
int current_value = 0;
int running = 1;

void displayDigit(int num, int position) {
    digitalWrite(SELECT_DISPLAY, position);
    for (int i = 0; i < 7; i++) {
        digitalWrite(SSD_PINS[i], digits[num][i]);
    }
}

void* displayLoop(void* arg) {
    while (running) {
        int tens = (current_value / 10) % 10;
        int ones = current_value % 10;
        
        displayDigit(tens, 0);
        usleep(10000);
        displayDigit(ones, 1);
        usleep(10000);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <valeur_max>", argv[0]);
        return 1;
    }
    max_value = atoi(argv[1]);
    if (max_value < 0 || max_value > 99) {
        printf("Erreur : La valeur maximale doit être comprise entre 0 et 99\n");
        return 1;
    }

    if (wiringPiSetupGpio() == -1) {
        printf("Erreur d'initialisation de wiringPi\n");
        return 1;
    }
    for (int i = 0; i < 7; i++) {
        pinMode(SSD_PINS[i], OUTPUT);
    }
    pinMode(SELECT_DISPLAY, OUTPUT);

    pthread_t thread;
    pthread_create(&thread, NULL, displayLoop, NULL);

    while (current_value <= max_value) {
        sleep(1);
        current_value++;
    }

    running = 0;
    pthread_join(thread, NULL);
    
    for (int i = 0; i < 7; i++) {
        digitalWrite(SSD_PINS[i], 0);
    }
    return 0;
}
