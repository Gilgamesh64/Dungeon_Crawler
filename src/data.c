#include "data.h"
#include "stdio.h"

GameData *get_game_data(void) {
    static GameData data = {DEFAULT_HEALTH, DEFAULT_MONEY, DEFAULT_ITEMS, DEFAULT_QUESTS};
    return &data;
}

/**
 * Prints current game_data
 */
void print_data(){
    GameData *s = get_game_data();

    printf("%d P.VITA , %d MONETE , %d OGGETTI , %d MISSIONI COMPLETATE",
            s->health_points,
            s->coins,
            s->items,
            s->missions_completed);
}