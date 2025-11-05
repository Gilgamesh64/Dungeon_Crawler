#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @return the result of the die roll
 */
int roll_dice(void){
    return (rand() % DICE_SIDES) + 1;
}

/**
 * Clears the terminal screen
 */
void clear_screen(void){
    printf("\033[2J\033[H");
    fflush(stdout);
}

/**
 * Waits for a user click to continue
 * @param string to show the user
 */
void click_to_continue(char* string){
    printf("%s", string);
    getchar();
}

/**
 * @param prompt to show the user
 * @return a string from the user
 */
char *get_string(const char *prompt) {
    static char buffer[256];

    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; 
    }
    return buffer;
}

/**
 * Gets a string to the user and puts it into a given buffer
 * @param buffer to put the string in
 * @param size of the buffer
 * @param prompt to show the user
 */
void get_string_buffer(char *buffer, size_t size, const char *prompt) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}