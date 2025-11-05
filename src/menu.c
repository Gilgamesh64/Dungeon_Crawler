#include "menu.h"
#include "utils.h"
#include "data.h"
#include "savings.h"
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
    va_list args;
    va_start(args, first);

    const char *str = first;

    int count = 1;
    int selection = -1;

    printf("%s\n", prompt); 


    while (str != NULL) {
        printf("%d. %s\n", count, str);
        count++;
        str = va_arg(args, const char *);
    }
    va_end(args);

    do {
        printf("Select [1-%d]: ", count - 1);
        if (scanf("%d", &selection) != 1) {
            while (getchar() != '\n');
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
    int selected = select_option("Menu principale: ", "Nuova partita", "Carica salvataggio", NULL);
    switch (selected){
    case 1:
        village_menu();
        break;
    
    case 2: 
        save_menu();
        break;
    default:
        break;
    }
}

void save_menu(){
    clear_screen();
    char file_buffers[MAX_FILES][MAX_LINE];
    const char *all_text[MAX_FILES];

    for (int i = 0; i < MAX_FILES; i++) {
        all_text[i] = file_buffers[i];
    }

    int total_files = get_all_saves((char **)all_text);

    if (total_files <= 0) {
        printf("Nessun salvataggio trovato.\n");
        return;
    }
    int choice = select_option_array("Seleziona un file di salvataggio:", all_text, total_files);

    char filename[100];
    get_file_name(filename, get_nth_index(choice));

    printf("\n");
    int operation = select_option("Seleziona un opzione sul salvataggio: ", "Carica", "Elimina", NULL);

    switch (operation){
    case 1:
        load(filename);
        village_menu();
        break;
    
    case 2: 
        int sure = select_option("Sei sicuro di voler eliminare definitivamente il salvataggio?: ", "SI", "NO ASPE", NULL);
        if(sure == 1){
            remove(filename);
            main_menu();
        }
        else save_menu();
        break;
    default:
        break;
    }
}

void village_menu(){
    clear_screen();
    int selected = select_option("Menu del villaggio: ", "Riposati", "Inventario", "Salva la partita", "Esci", NULL);
    switch (selected){
    case 1:
        get_game_data() -> health_points = 20;
        click_to_continue("Health restored!\n");
        village_menu();
        break;
    case 3:
        save();
        click_to_continue("Saved\n");
        village_menu();
        break;
    case 4:
        break;
    
    default:
        break;
    }
}