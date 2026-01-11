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
    printf("%s\nClicca per continuare\n->", string);

    int c;

    while ((c = getchar()) != '\n' && c != EOF) {} //clear buffer
    getchar();
}


char *get_string(const char *prompt) {
    static char buffer[256];

    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; 
    }
    return buffer;
}


void get_string_buffer(char *buffer, size_t size, const char *prompt) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}