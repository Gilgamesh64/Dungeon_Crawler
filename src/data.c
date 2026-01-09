#include "data.h"
#include "entity.h"
#include "item.h"
#include <stdio.h>

GameData *get_game_data(void) {
    static GameData data = {DEFAULT_HEALTH, DEFAULT_MONEY, DEFAULT_ITEMS, DEFAULT_QUESTS};
    return &data;
}

/**
 * Prints current game_data
 */

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