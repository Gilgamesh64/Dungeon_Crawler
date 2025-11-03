#include "data.h"
#include "stdio.h"

GameData *get_game_data(void) {
    static GameData data = {20, 0, 0, 0};
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