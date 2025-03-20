#ifndef GPIO_H
#define GPIO_H

char JA[8] = {8, 10, 9, 11, 19, 21, 20, 18};
char JB[8] = {7, 10, 9, 11, 26, 13, 3, 2};
char JC[8] = {16, 14, 15, 17, 4, 12, 5, 6};

void gpio_set_direction(int pin, int direction);
void gpio_set_value(int pin, int value);
int  gpio_get_value(int pin );
#endif

