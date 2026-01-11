#include "data.h"

GameData *get_game_data(void) {
    static GameData data = {DEFAULT_HEALTH, DEFAULT_MONEY, DEFAULT_ITEMS, DEFAULT_QUESTS};
    return &data;
}

/**
 * Prints current game_data
 */


/*
    controls the HP of the character 
    hp > 20? if so the function will cap them at the maximum of 20
    if the health points go below 1 then the it's game over 

*/
void health_control(){
    if(get_game_data()->health_points>20){
        get_game_data()->health_points = 20;
    }
    if(get_game_data()->health_points <= 0){
        printf("sei morto!\n");
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