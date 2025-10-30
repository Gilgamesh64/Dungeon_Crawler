#include "menu.h"
#include "utils.h"
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
int selectOption(const char *prompt, const char *first, ...) {
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

void main_menu(){
    clear_screen();
    int selected = selectOption("Pick a menu option: ", "New save", "Load save", NULL);
    switch (selected)
    {
    case 1:
        printf("Start game!\n");
        village_menu();
        break;
    
    case 2: 
        printf("Loading save menu!\n");
        load_save_menu();
    default:
        break;
    }
}

void load_save_menu(){
    clear_screen();
    int selected = selectOption("Load save: ", "Save 1", "Save 2", NULL);
    printf("\n");
    int operation = selectOption("Select option for saving: ", "Load", "Delete", NULL);

    printf("Selected: %d with operation %d\n", selected, operation);
}

void village_menu(){
    clear_screen();
    int selected = selectOption("Menu del villaggio: ", "Riposati", "Inventario", "Salva la partita", "Esci", NULL);
    printf("Selection: %d", selected);
}