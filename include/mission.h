#ifndef MISSION_H
#define MISSION_H

#include "entity.h"
#define MAX_DIM 10

typedef struct{
    const Entity* rooms[MAX_DIM];
    int dim;
    int current_room;
} Dungeon;

static Dungeon dungeon;

void generate_dungeon(int current_level);
Dungeon* get_dungeon();

#endif