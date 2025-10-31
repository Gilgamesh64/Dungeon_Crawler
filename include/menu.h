#ifndef MENU_H
#define MENU_H


int select_option(const char *prompt, const char *first, ...);
int select_option_array(const char *prompt, const char **options, int count);
void main_menu();
void save_menu();
void village_menu();

#endif