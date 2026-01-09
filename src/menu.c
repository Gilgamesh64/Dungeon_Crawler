#include "menu.h"
#include "data.h"
#include "entity.h"
#include "item.h"
#include "mission.h"
#include "savings.h"
#include "utils.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Creates a menu asking the user for a selection
 * Ex: select("Pick an option: ", "Menu", "Settings", "Quit", NULL)
 * @param prompt to ask the user for input
 * @param first list of strings that will form the menu ended with NULL
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
            while (getchar() != '\n')
                ;
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
    if (count <= 0)
        return -1;

    int selection = -1;

    printf("%s\n", prompt);
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, options[i]);
    }

    do {
        printf("Select [1-%d]: ", count);
        if (scanf("%d", &selection) != 1) {
            while (getchar() != '\n')
                ;
        }
    } while (selection <= 0 || selection > count);

    return selection;
}

void main_menu() {
    clear_screen();
    int selected = select_option("Menu principale: ", "Nuova partita", "Carica salvataggio", "Spawn Enemy", NULL);
    switch (selected) {
    case 1:
        village_menu();
        break;

    case 2:
        save_menu();
        break;
    case 3:
        Entity spawned = spawn_entity(0);
        printf("Spawned: %s\n", spawned.name);
        click_to_continue("Confirm ");
        main_menu();
    default:
        break;
    }
}

void save_menu() {
    clear_screen();

    int file_count = count_files();

    if (file_count <= 0) {
        printf("Nessun salvataggio trovato.\n");
        return;
    }

    char file_buffers[file_count][100];
    const char *all_text[file_count];

    for (int i = 0; i <= file_count; i++) {
        all_text[i] = file_buffers[i];
    }

    get_all_saves((char **)all_text);

    int choice = select_option_array("Seleziona un file di salvataggio:", all_text, file_count);

    char filename[100];
    get_file_name(filename, get_nth_index(choice));

    printf("\n");
    int operation = select_option("Seleziona un opzione sul salvataggio: ", "Carica", "Elimina", NULL);

    switch (operation) {
    case 1:
        load(filename);
        village_menu();
        break;

    case 2:
        int sure = select_option("Sei sicuro di voler eliminare definitivamente il salvataggio?: ", "SI", "NO ASPE", NULL);
        if (sure == 1) {
            remove(filename);
            main_menu();
        } else
            save_menu();
        break;
    default:
        break;
    }
}

void inventory_menu() {
    clear_screen();
    printf("Inventario dell'Eroe\n");

    printf("Spada: %s\n", has_sword() ? "Non in possesso" : "In possesso");
    printf("Armatura: %s\n", has_armor() ? "Non in possesso" : "In possesso");
    printf("Chiave: %s\n", has_key() ? "Non in possesso" : "In possesso");
    printf("Spada dell'eroe: %s\n", has_hero_sword() ? "Non in possesso" : "In possesso");
    printf("Pozioni: %d\n", get_potions());

    click_to_continue("");
    village_menu();
}

void shop_menu() {
    clear_screen();

    printf("Shop Menu\n");

    int items = get_game_data()->items;

    int select = select_option("Seleziona un item da comprare: ", "Pozione curativa", "Spada", "Armatura", NULL);
    bool can_buy = get_item(select).cost <= get_game_data()->coins;

    if(select == 1) can_buy |= !has_sword();
    if(select == 2) can_buy |= !has_armor();

    if(!can_buy){
        click_to_continue("Non puoi comprare questo item");
        shop_menu();
    }

    switch (select){
    case 0:
        add_potion();
        break;
    
    case 1:
        set_sword();

    case 2:
        set_armor();
    
    default:
        break;
    }

    click_to_continue("Successful");
    mission_menu();
}

void village_menu() {
    clear_screen();
    int selected = select_option("Menu del villaggio: ", "Inizia missione", "Riposati", "Inventario", "Salva la partita", "Esci", NULL);
    switch (selected) {
    case 1:
        mission_selection_menu();
        break;
    case 2:
        get_game_data()->health_points = 20;
        clear_screen();
        click_to_continue("Health restored!\n");
        village_menu();
        break;
    case 3:
        inventory_menu();
        break;
    case 4:
        save();
        clear_screen();
        click_to_continue("Saved\n");
        village_menu();
        break;
    case 5:
        break;

    default:
        break;
    }
}

void mission_selection_menu() {

    clear_screen();
    int selected = select_option("Menu di Selezione Missione: ", "Palude Putrescente", "Magione Infestata", "Grotta di Cristallo", NULL);

    generate_dungeon(selected);

    /*for (int i = 0; i < get_dungeon()->dim; i++) {
        printf("%s\n", get_dungeon()->rooms[i].name);
    }*/

    mission_menu();
}

void mission_menu() {
    clear_screen();
    int selected = select_option("Menu di Missione: ", "Esplora stanza del Dungeon", "Negozio", "Inventario", "Torna al Villaggio", NULL);

    switch (selected) {
    case 1:
        get_dungeon()->current_room++;
        room_menu();
        break;
    case 2:
        shop_menu();
        break;
    case 3:
        inventory_menu();
        break;
    case 4:

        break;

    default:
        break;
    }
}

void room_menu() {
    int room = get_dungeon()->current_room;
    if (get_dungeon()->rooms[room].trap) {
        trap_menu();
    } else if (strcmp(get_dungeon()->rooms[room].name, "Stanza Vuota")) {
        printf("La stanza è vuota...\n");
    } else {
        combat_menu();
    }
}

void trap_menu() {
    int room = get_dungeon()->current_room;
    int tipo_trappola = get_dungeon()->rooms[room].fatal;

    printf("Hai attivato una trappola: ");

    switch (tipo_trappola) {
    case 0:
        if (get_dungeon()->rooms[room].damage != 0) {
            printf("L'eroe ha preso %d danno\n", get_dungeon()->rooms[room].damage);
        } else {
            printf("L'eroe ha perso %d monete.\n", get_dungeon()->rooms[room].coins);
        }

        get_game_data()->health_points -= get_dungeon()->rooms[room].damage;
        get_game_data()->coins += get_dungeon()->rooms[room].coins;
        break;

    case 1:
        // get_game_data()->dungeonAttuale[room].damage = roll_dice();
        get_game_data()->health_points -= get_dungeon()->rooms[room].damage;
        printf("L'eroe ha preso %d danno e rimane con %d punti vita\n", get_dungeon()->rooms[room].damage, get_game_data()->health_points);
        break;

    case 2:
        // il lancio della moneta è semplicemente un controllo pari/dispari
        if (roll_dice() % 2 == 0) {
            get_game_data()->health_points -= get_dungeon()->rooms[room].damage;
            printf("L'eroe ha preso %d danno e rimane con %d punti vita\n", get_dungeon()->rooms[room].damage, get_game_data()->health_points);
        } else {
            printf("L'eroe ha guadagnato %d monete.\n", get_dungeon()->rooms[room].coins);
            get_game_data()->coins += get_dungeon()->rooms[room].coins;
        }
        break;

    default:
        break;
    }
    click_to_continue(NULL);
    mission_menu();
}

void combat_menu() {
    int room = get_dungeon()->current_room;
    int danno_giocatore;

    printf("L'eroe incontra un %s e inizia il combattimento.\n", get_dungeon()->rooms[room].name);

    do {
        printf("Viene lanciato un dado per stabilire l'attacco dell'eroe\n");
        danno_giocatore = roll_dice();
        printf("il risultato: %d\n", danno_giocatore);
        if (danno_giocatore >= get_dungeon()->rooms[room].fatal) {
            printf("Il %s viene sconfitto (%d>%d). l'eroe rimane con %d punti vita e riceve %d monete \n",
                   get_dungeon()->rooms[room].name,
                   get_dungeon()->rooms[room].fatal,
                   danno_giocatore,
                   get_game_data()->health_points,
                   get_dungeon()->rooms[room].coins);
            get_game_data()->coins += get_dungeon()->rooms[room].coins;
        } else {
            printf("Attacco non sufficente per sconfiggere lo %s (%d<Colpo Fatale=%d) \n",
                   get_dungeon()->rooms[room].name,
                   danno_giocatore,
                   get_dungeon()->rooms[room].fatal);
            get_game_data()->health_points -= get_dungeon()->rooms[room].damage;
            printf("Il %s infligge %d danni all'eroe. L'eroe rimane con %d punti vita\n",
                   get_dungeon()->rooms[room].name,
                   get_dungeon()->rooms[room].damage,
                   get_game_data()->health_points);
        }

    } while (danno_giocatore < get_dungeon()->rooms[room].fatal);

    click_to_continue(NULL);
    mission_menu();
}



