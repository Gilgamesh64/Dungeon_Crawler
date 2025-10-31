#include "menu.h"
#include "utils.h"
#include "data.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * Creates a menu asking the user for a selection
 * @param prompt to ask the user for input
 * @param first list of strings that will form the menu ended with NULL
 * Ex: select("Pick an option: ", "Menu", "Settings", "Quit", NULL)
 * @return selected number
 */
int select_option(const char *prompt, const char *first, ...) {
    va_list args; //declare args list
    va_start(args, first);

    const char *str = first;

    int count = 1;
    int selection = -1;

    printf("%s\n", prompt); 


    //loops the args and prints the enumerated menu
    while (str != NULL) {
        printf("%d. %s\n", count, str);
        count++;
        str = va_arg(args, const char *); //advances in the args array
    }
    va_end(args);

    do {
        printf("Select [1-%d]: ", count - 1);
        if (scanf("%d", &selection) != 1) { //asks the user for a valid number
            while (getchar() != '\n'); //flushes the stdin
        }
    } while (selection <= 0 || selection >= count);

    return selection;
}

#include <stdio.h>

/**
 * Creates a menu asking the user for a selection
 * @param prompt to ask the user for input
 * @param options array of strings to display as menu
 * @param count number of strings in the array
 * @return selected number (1-based index)
 */
int select_option_array(const char *prompt, const char **options, int count) {
    if (count <= 0) return -1;

    int selection = -1;

    printf("%s\n", prompt);
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, options[i]);
    }

    do {
        printf("Select [1-%d]: ", count);
        if (scanf("%d", &selection) != 1) {
            while (getchar() != '\n');
        }
    } while (selection <= 0 || selection > count);

    return selection;
}


void main_menu(){
    clear_screen();
    int selected = select_option("Pick a menu option: ", "New save", "Load save", NULL);
    switch (selected)
    {
    case 1:
        printf("Start game!\n");
        village_menu();
        break;
    
    case 2: 
        printf("Loading save menu!\n");
        save_menu();
    default:
        break;
    }
}

void save_menu(){
    clear_screen();

    printf("\n");
    int operation = select_option("Select option for saving: ", "Load", "Delete", NULL);
}

void village_menu(){
    clear_screen();
    int selected = select_option("Menu del villaggio: ", "Riposati", "Inventario", "Salva la partita", "Esci", NULL);
    printf("Selection: %d", selected);
}