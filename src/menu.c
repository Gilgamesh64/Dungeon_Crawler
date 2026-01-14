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
        printf("Seleziona [1-%d]: ", count - 1);
        if (scanf("%d", &selection) != 1) {
            while (getchar() != '\n')
                ;
        }
    } while (selection <= 0 || selection >= count);

    return selection - 1;
}

/**
 * Creates a menu asking the user for a selection
 * @param prompt to ask the user for input
 * @param options array of strings to display as menu
 * @param count number of strings in the array
 * @return selected number (0-based index)
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
        printf("Seleziona [1-%d]: ", count);
        if (scanf("%d", &selection) != 1) {
            while (getchar() != '\n')
                ;
        }
    } while (selection <= 0 || selection > count);

    return selection - 1;
}

bool has_cheats = true;

void main_menu() {
    clear_screen();
    if (has_cheats) {
        main_menu_cheats();
        return;
    }
    printf("Menu principale:\n");
    printf("1. Nuova partita\n");
    printf("2. Carica salvataggio\n");

    char *konami = "wwssadadba ";
    int konami_index = 0;

    int selection = 0;
    char input;

    while (1) {
        printf("Seleziona [1-2]: ");

        input = getchar();

        while (getchar() != '\n')
            ;

        if (input == '1' || input == '2') {
            selection = input - '1';
            break;
        }

        if (input == konami[konami_index]) {
            konami_index++;

            if (konami[konami_index] == '\0') {
                has_cheats = true;
                printf("CHEATS!\n");
                main_menu_cheats();
            }
        } else {
            konami_index = 0;
        }
    }
    switch (selection) {
    case 0:
        reset_data();
        village_menu();
        break;

    case 1:
        save_menu();
        break;
    default:
        break;
    }
}

void main_menu_cheats() {
    clear_screen();
    switch (select_option("Menu principale:", "Nuova partita", "Carica salvataggio", "Trucchi", NULL)) {
    case 0:
        reset_data();
        village_menu();
        break;
    case 1:
        save_menu();
        break;
    case 2:
        save_menu();
        break;
    default:
        break;
    }
}

void village_menu() {
    clear_screen();
    switch (select_option("Menu del villaggio: ", "Inizia missione", "Riposati", "Inventario", "Salva la partita", "Esci", NULL)) {
    case 0:
        mission_selection_menu();
        break;
    case 1:
        get_game_data()->health_points = 20;
        click_to_continue("Vita ripristinata!");
        village_menu();
        break;
    case 2:
        inventory_menu();
        click_to_continue("Torna al menu di villaggio");
        village_menu();
        break;
    case 3:
        save();
        click_to_continue("Operazione effettuata");
        village_menu();
        break;

    default:
        break;
    }
}

void mission_selection_menu() {
    clear_screen();

    if (is_final_mission_unlocked()) {
        const char *available_missions[4];
        int available_indexes[4];
        int available_count = 0;

        for (int i = 0; i < 4; i++) {
            if (!has_completed(i)) {
                available_missions[available_count] = get_mission_name(i);
                available_indexes[available_count] = i;
                available_count++;
            }
        }
        int choice = select_option_array("Menu di Selezione Missione: ", available_missions, available_count);

        int mission_index = available_indexes[choice];
        if (mission_index == BOSS_ID)
            boss_menu();
        else {
            generate_dungeon(mission_index);

            mission_menu();
        }

        return;
    }
    const char *available_missions[3];
    int available_indexes[3];
    int available_count = 0;

    for (int i = 0; i < 3; i++) {
        if (!has_completed(i)) {
            available_missions[available_count] = get_mission_name(i);
            available_indexes[available_count] = i;
            available_count++;
        }
    }

    int choice = select_option_array("Menu di Selezione Missione: ", available_missions, available_count);

    int mission_index = available_indexes[choice];
    generate_dungeon(mission_index);

    mission_menu();
}

void mission_menu() {
    clear_screen();

    switch (select_option("Menu di Missione: ", "Esplora stanza del Dungeon", "Negozio", "Inventario", "Torna al Villaggio", NULL)) {
    case 0:
        room_menu();
        get_dungeon()->current_room++;
        break;
    case 1:
        shop_menu();
        break;
    case 2:
        inventory_menu();
        break;
    case 3:
        if (!select_option("Ti costera' 50 monete, sei sicuro?", "SI", "NO", NULL)) {
            if (get_game_data()->coins >= 50) {
                get_game_data()->coins -= 50;
                complete_mission(get_dungeon()->dungeon);
                click_to_continue("Ritornando al menu di villaggio\n");
                village_menu();
            } else {
                printf("Non hai abbastanza monete\n");
            }
        }
        break;

    default:
        break;
    }
    click_to_continue("");
    mission_menu();
}

void inventory_menu() {
    clear_screen();
    printf("Inventario dell'Eroe\n");
    printf("Monete: %d\n", get_game_data()->coins);
    printf("Vita: %d\n\n", get_game_data()->health_points);

    printf(has_completed(SWAMP_ID) ? "Palude Putrescente completata\n" : "");
    printf(has_completed(MANSION_ID) ? "Magione Infestata completata\n" : "");
    printf(has_completed(CAVE_ID) ? "Grotta di Cristallo completata\n" : "");
    printf(has_completed(BOSS_ID) ? "Boss Finale completato\n\n" : "");

    printf("Spada: %s\n", has_item(SWORD_ID) ? "In possesso" : "Non in possesso");
    printf("Armatura: %s\n", has_item(ARMOR_ID) ? "In possesso" : "Non in possesso");
    printf("Chiave: %s\n", has_item(KEY_ID) ? "In possesso" : "Non in possesso");
    printf("Spada dell'eroe: %s\n", has_item(HERO_SWORD_ID) ? "In possesso" : "Non in possesso");
    printf("Pozioni: %d\n", get_potions());

    if (get_potions() > 0) {
        if (!select_option("Desideri consumare una pozione?", "SI", "NO", NULL)) {
            sub_potion();
            get_game_data()->health_points += roll_dice();
            health_control();
        }
    }
}

void shop_menu() {
    clear_screen();

    printf("Shop Menu\n");

    printf("Monete: %d\n", get_game_data()->coins);
    int select = select_option("Seleziona un item da comprare: ", "Pozione curativa -> 4", "Spada -> 5", "Armatura -> 10", "Esci", NULL);
    if (select == 3)
        return;

    bool can_buy = get_item(select).cost <= get_game_data()->coins;
    if (!can_buy) {
        printf("Non hai abbastanza soldi!\n");
        return;
    }

    if (select == 1)
        can_buy &= !has_item(SWORD_ID);
    if (select == 2)
        can_buy &= !has_item(ARMOR_ID);

    if (!can_buy) {
        printf("Possiedi già questo item\n");
        return;
    }

    switch (select) {
    case 0:
        add_potion();
        get_game_data()->coins -= 4;
        break;

    case 1:
        set_item(SWORD_ID);
        get_game_data()->coins -= 5;
        break;

    case 2:
        set_item(ARMOR_ID);
        get_game_data()->coins -= 10;
        break;

    default:
        break;
    }
    printf("Comprato con successo!\n");
}

void save_menu() {
    clear_screen();

    int file_count = count_files();

    if (file_count <= 0) {
        printf("Nessun salvataggio trovato.\n");
        return;
    }

    char file_buffers[file_count][256];
    const char *all_text[file_count];

    for (int i = 0; i <= file_count; i++) {
        all_text[i] = file_buffers[i];
    }

    get_all_saves((char **)all_text);

    if (has_cheats)
        printf("I trucchi sono attivi!\n");

    int choice = select_option_array("Seleziona un file di salvataggio:", all_text, file_count);

    char filename[100];
    get_file_name(filename, get_nth_index(choice + 1));

    printf("\n");

    if (!has_cheats) {
        switch (select_option("Seleziona un opzione sul salvataggio: ", "Carica", "Elimina", NULL)) {
        case 0:
            load(filename);
            village_menu();
            break;

        case 1:
            if (!select_option("Sei sicuro di voler eliminare definitivamente il salvataggio?: ", "SI", "NO", NULL)) {
                remove(filename);
                main_menu();
            } else
                save_menu();
            break;
        default:
            break;
        }
    } else {
        switch (select_option("Seleziona un opzione sul salvataggio: ", "Carica", "Elimina", "Modifica", NULL)) {
        case 0:
            load(filename);
            village_menu();
            break;

        case 1:
            if (!select_option("Sei sicuro di voler eliminare definitivamente il salvataggio?: ", "SI", "NO", NULL)) {
                remove(filename);
                main_menu();
            } else
                save_menu();
            break;
        case 2:
            switch (select_option("Seleziona l'opzione per i trucchi:", "Vita", "Monete", "Sblocco missione finale", NULL)) {
            case 0:
                int health_tmp = 0;
                printf("Inserisci la vita del giocatore: ");
                if (scanf("%u", &health_tmp) == 1 && health_tmp >= 0) {
                    unsigned int health = (unsigned int)health_tmp;
                    load(filename);
                    get_game_data()->health_points = health;
                    save();
                } else
                    printf("Valore non valido!\n");

                main_menu_cheats();

                break;
            case 1:
                int money_tmp = 0;
                printf("Inserisci il numero di monete del giocatore: ");
                if (scanf("%u", &money_tmp) == 1 && money_tmp >= 0) {
                    unsigned int money = (unsigned int)money_tmp;
                    load(filename);
                    get_game_data()->coins = money;
                    save();
                } else
                    printf("Valore non valido!\n");

                main_menu_cheats();
                break;
            case 2:
                is_boss_unlocked_cheating = true;
                main_menu_cheats();
                break;
            default:
                break;
            }
        default:
            break;
        }
    }
}

void room_menu() {
    int room = get_dungeon()->current_room;

    if (get_dungeon()->rooms[room]->trap) {
        trap_menu();
    } else if (!strcmp(get_dungeon()->rooms[room]->name, "Stanza Vuota")) {
        printf("La stanza e' vuota...\n");
    } else {
        combat_menu();
    }
}

void trap_menu() {
    int room = get_dungeon()->current_room;
    int tipo_trappola = get_dungeon()->rooms[room]->fatal;

    printf("Hai attivato una trappola: %s\n", get_dungeon()->rooms[room]->name);

    switch (tipo_trappola) {
    case 0:
        if (get_dungeon()->rooms[room]->damage != 0) {
            printf("L'eroe ha preso %d danno\n", get_dungeon()->rooms[room]->damage);
            if (has_item(ARMOR_ID)) {
                printf("Grazie all'armatura subisci 1 di danno in meno\n");
                get_game_data()->health_points++;
            }
        } else {
            printf("L'eroe ha perso %d monete.\n", get_dungeon()->rooms[room]->coins);
        }

        get_game_data()->health_points -= get_dungeon()->rooms[room]->damage;
        get_game_data()->coins += get_dungeon()->rooms[room]->coins;
        break;

    case 1:
        int dmg = roll_dice();
        get_game_data()->health_points -= dmg;
        printf("L'eroe ha preso %d danno e rimane con %d punti vita\n", dmg, get_game_data()->health_points);
        if (has_item(ARMOR_ID)) {
            printf("Grazie all'armatura subisci 1 di danno in meno\n");
            get_game_data()->health_points++;
        }
        break;

    case 2:
        // il lancio della moneta è semplicemente un controllo pari/dispari
        if (roll_dice() % 2 == 0) {
            get_game_data()->health_points -= get_dungeon()->rooms[room]->damage;
            printf("L'eroe ha preso %d danno e rimane con %d punti vita\n", get_dungeon()->rooms[room]->damage, get_game_data()->health_points);
            if (has_item(ARMOR_ID)) {
                printf("Grazie all'armatura subisci 1 di danno in meno\n");
                get_game_data()->health_points++;
            }
        } else {
            printf("L'eroe ha guadagnato %d monete.\n", get_dungeon()->rooms[room]->coins);
            get_game_data()->coins += get_dungeon()->rooms[room]->coins;
        }
        break;

    default:
        break;
    }
    health_control();
}

void combat_menu() {
    int room = get_dungeon()->current_room;
    int player_damage;

    printf("L'eroe incontra un %s e inizia il combattimento.\n", get_dungeon()->rooms[room]->name);
    do {
        printf("Viene lanciato un dado per stabilire l'attacco dell'eroe\n");
        player_damage = roll_dice();

        printf("il risultato: %d\n", player_damage);

        apply_sword(room);

        if (player_damage >= get_dungeon()->rooms[room]->fatal) { // kill range
            printf("Il %s viene sconfitto (%d>%d). l'eroe rimane con %d punti vita e riceve %d monete \n",
                   get_dungeon()->rooms[room]->name,
                   get_dungeon()->rooms[room]->fatal,
                   player_damage,
                   get_game_data()->health_points,
                   get_dungeon()->rooms[room]->coins);
            get_game_data()->coins += get_dungeon()->rooms[room]->coins;

        } else { // did not kill
            printf("Attacco non sufficente per sconfiggere lo %s (%d<Colpo Fatale=%d) \n",
                   get_dungeon()->rooms[room]->name,
                   player_damage,
                   get_dungeon()->rooms[room]->fatal);

            if (!strcmp(get_dungeon()->rooms[room]->name, "Drago Antico") && dragon_combat())
                continue;

            get_game_data()->health_points -= get_dungeon()->rooms[room]->damage;

            printf("Il %s infligge %d danni all'eroe. L'eroe rimane con %d punti vita\n",
                   get_dungeon()->rooms[room]->name,
                   get_dungeon()->rooms[room]->damage,
                   get_game_data()->health_points);
            apply_armor();
        }

        health_control();
        if (player_damage < get_dungeon()->rooms[room]->fatal)
            click_to_continue("");
    } while (player_damage < get_dungeon()->rooms[room]->fatal);

    if (!strcmp(get_dungeon()->rooms[room]->name, (&LEVEL_TABLE[get_dungeon()->dungeon][get_dungeon()->target_entity])->name)) {
        get_dungeon()->target_count--;
    }

    if (!strcmp(get_dungeon()->rooms[room]->name, "Drago Antico")) { // se la stanza appena battuta è i ldrago antico, l'eroe riceve la spada dell'eroe
        printf("Complimenti! Hai sconfitto il Drago Antico e ottenuto la Spada dell'Eroe!\n");
        set_item(HERO_SWORD_ID);
    }

    if (get_dungeon()->target_count <= 0) {
        complete_mission(get_dungeon()->dungeon);
        click_to_continue("Complimenti! Hai completato la missione!\n");
        clear_screen();
        click_to_continue("Torna al villaggio");
        village_menu();
    }
}

bool dragon_combat() {
    printf("Attenzione! Stai per affrontare il Drago Antico\n");

    int rnd = rand() % 500 + 1;
    bool is_in = is_in_paduvan_sequence(rnd);

    char text[128];

    snprintf(
        text,
        sizeof(text),
        "Il Drago ti chiede: il numero %d fa parte della sequenza di Padovan?",
        rnd);

    if (is_in == !select_option(text, "SI", "NO", NULL)) {
        printf("Hai indovinato! Il drago non ti attacca\n");
        return true;
    }
    return false;
}

// P(n) = P(n-2) + P(n-3)
bool is_in_paduvan_sequence(int n) {
    int pN = 1, pNmin1 = 1, pNmin2 = 1, pNmin3 = 1;

    if (n == 1)
        return true;

    while (pN < 500) {
        if (pN == n) {
            return true;
        }
        pN = pNmin2 + pNmin3;
        pNmin3 = pNmin2;
        pNmin2 = pNmin1;
        pNmin1 = pN;
    }

    return false;
}

void apply_armor() {
    if (has_item(ARMOR_ID)) {
        get_game_data()->health_points += 1;
        printf("Grazie all'armatura subisci 1 di danno in meno\n");
    }
}

int apply_sword(int room) {
    int bonus = 0;
    if (has_item(HERO_SWORD_ID)) {
        bonus += 2;
        printf("Grazie alla spada dell'eroe, il giocatore effettua due di danno aggiuntivi\n");

        if (!strcmp(get_dungeon()->rooms[room]->name, (&LEVEL_TABLE[0][5])->name)) { // Generale Orco della Palude Putrescente
            bonus += 1;                                                              // il generale orco prende un danno extra dalla spada dell'eroe
            printf("Grazie alla spada dell'eroe, il Generale Orco subisce uno di danno in più");
        }

    } else if (has_item(SWORD_ID)) {
        bonus += 1;
        printf("Grazie alla spada, il giocatore effettua uno di danno aggiuntivo\n");
    }
    return bonus;
}

void boss_menu() {
    clear_screen();
    complete_mission(BOSS_ID);
    save();
    int wins = 0;

    printf("Incontri il Signore Oscuro e inizia il combattimento!\n");
    printf("Devi vincere 3 round per sconfiggerlo!\n");

    for (int i = 0; i < 5; i++) {
        int selection = select_option("Scegli la tua azione: ", "Scudo", "Magia", "Spada", NULL);
        switch (selection) {
        case 1:
            printf("L'eroe ha scelto lo Scudo\n");
            break;
        case 2:
            printf("L'eroe ha scelto la Magia\n");
            break;
        case 3:
            printf("L'eroe ha scelto la Spada\n");
            break;

        default:
            break;
        }

        if (shield_magic_sword(selection)) {
            printf("Hai vinto questo round contro il Signore Oscuro!\n");
            wins++;
        }
    }
}

bool shield_magic_sword(int player_choice) {
    // shield = 1, magic = 2, sword = 3
    int computer_choice = roll_dice() / 2;

    switch (computer_choice) {
    case 1:
        printf("Il Signore Oscuro ha scelto lo Scudo\n");
        break;
    case 2:
        printf("Il Signore Oscuro ha scelto la Magia\n");
        break;
    case 3:
        printf("Il Signore Oscuro ha scelto la Spada\n");
        break;

    default:
        break;
    }

    // DA DECIDERE COME GESTIRE I PAREGGI
    if (player_choice == computer_choice) {
        return false;
        // return rock_paper_scissors(player_choice); //draw, play again
    }

    return player_choice == (computer_choice % 3) + 1;
}