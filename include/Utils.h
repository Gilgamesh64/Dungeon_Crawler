#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

#define DICE_SIDES 6


int roll_dice(void);
void clear_screen(void);
void click_to_continue(char* string);
char* get_string(const char *prompt);
void get_string_buffer(char *buffer, size_t size, const char *prompt);

#endif
