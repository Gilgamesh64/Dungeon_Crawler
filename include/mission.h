#ifndef MISSION_H
#define MISSION_H

#include "entity.h"
#include "entity.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>


#define MAX_DIM 10

typedef struct{
    const Entity* rooms[MAX_DIM];
    int dim;
    int current_room;
} Dungeon;

static Dungeon dungeon;

/**
 * Generates a dungeon for the current level
 * @param current_level index of the current level
 */
void generate_dungeon(int current_level);

/**
 * Returns the current dungeon
 */
Dungeon* get_dungeon();

#endif