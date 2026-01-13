#include "data.h"
#include "entity.h"
#include "item.h"
#include "utils.h"
#include "menu.h"
#include <stdio.h>


GameData *get_game_data(void) {
    static GameData data = {DEFAULT_HEALTH, DEFAULT_MONEY, DEFAULT_ITEMS, DEFAULT_QUESTS};
    return &data;
}

void health_control(){
    if(get_game_data()->health_points>20){
        get_game_data()->health_points = 20;
    }
    if(get_game_data()->health_points <= 0){
        click_to_continue("\nGAME OVER!\n");
        reset_data();
        main_menu();
    }
}

void print_data() {
    GameData *s = get_game_data();

    printf("%s DATA, %s ORA, %d P.VITA , %d MONETE , %d OGGETTI , %d MISSIONI COMPLETATE\n",
           "Data",
           "Ora",
           s->health_points,
           s->coins,
           s->items,
           s->missions_completed);
}

void reset_data(){
    GameData* g = get_game_data();
    g -> health_points = DEFAULT_HEALTH;
    g -> coins = DEFAULT_MONEY;
    g -> items = DEFAULT_ITEMS;
    g -> missions_completed = DEFAULT_QUESTS;
}