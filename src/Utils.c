#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int roll_dice(void){
    return (rand() % DICE_SIDES) + 1;
}

void clear_screen(void){
    printf("\033[2J\033[H");
    fflush(stdout);
}


void click_to_continue(char* string){
    printf("%s\n", string && *string ? string : "Clicca per continuare");

    fflush(stdin);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}