/**
 * @file utils.h
 * 
 * @brief contains utility functions that come in handy elsewere
 */

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
 * 'Clicca per continuare' if empty
 */
void click_to_continue(char* string);

#endif
