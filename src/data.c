#include "data.h"
#include "entity.h"
#include <stdio.h>

GameData *get_game_data(void) {
    static GameData data = {DEFAULT_HEALTH, DEFAULT_MONEY, DEFAULT_ITEMS, DEFAULT_QUESTS, 0};
    return &data;
}

/**
 * Prints current game_data
 */

void generate_dungeon(int current_level) {
    // hey Cristian :3
    get_game_data()->dungeon_id = current_level;

    int n_stanze;
    int id_entity;

    switch (current_level) {
    case 0:
        n_stanze = 3;
        id_entity = 5;

        break;
    case 1:
        n_stanze = 1;
        id_entity = 4;
        break;

    case 2:
        n_stanze = 1;
        id_entity = 5;

        break;

    default:
        break;
    }

    for (int i = 0; i < DIM_DUNGEON; i++) {
/*
        if(i+n_stanze <= DIM_DUNGEON) {
            get_game_data()->dungeonAttuale[i] = spawn_entity(current_level);
        }
        else{
            get_game_data()->dungeonAttuale[i] = LEVEL_TABLE[current_level][id_entity];
            
        }

        if(get_game_data()->dungeonAttuale[i]==LEVEL_TABLE[current_level][id_entity]){
            n_stanze--;
            //hey cristian ;3
        }
            */

    }
}

void print_data() {
    GameData *s = get_game_data();

    printf("%d P.VITA , %d MONETE , %d OGGETTI , %d MISSIONI COMPLETATE",
           s->health_points,
           s->coins,
           s->items,
           s->dungeon_id);
}