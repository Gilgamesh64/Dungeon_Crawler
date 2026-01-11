#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

#define DICE_SIDES 6

/**
 * @return the result of the die roll
 */
int roll_dice(void);

/**
 * Clears the terminal screen
 */
void clear_screen(void);

/**
 * Waits for a user click to continue
 * @param string to show the user
 */
void click_to_continue(char* string);

/**
 * @param prompt to show the user
 * @return a string from the user
 */
char* get_string(const char *prompt);

/**
 * Gets a string to the user and puts it into a given buffer
 * @param buffer to put the string in
 * @param size of the buffer
 * @param prompt to show the user
 */
void get_string_buffer(char *buffer, size_t size, const char *prompt);

#endif
