#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "/home/mi005558/pi/work/common/common.h"
#include "/home/mi005558/pi/work/gpio/gpio.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Utilisation: %s <port> <combinaison> <duration>\n", argv[0]);
        return -1;
    }

    char *port = argv[1];
    int pattern = strtol(argv[2], NULL, 16);
    int duration = atoi(argv[3]);
	char* J;
	
	if(port[0] == 'a'){
		J = JA;
	}else if(port[0] == 'b'){
		J = JB;
	}else if(port[0] == 'c'){
		J = JC;
	}else{
		fprintf(stderr, "Port inconnu : %c\n", port[0]);
        return -1;
	}

    for (int i = 0; i < 8; i++) {
        gpio_set_direction(J[i], 1);
        if (pattern & (1 << i)) {
            gpio_set_value(J[i], 1);
        }
    }

	sleep(duration);

    for (int i = 0; i < 8; i++) {
        gpio_set_value(J[i], 0);
    }

    return 1;
}
