#ifndef MISSION_H
#define MISSION_H

#include "entity.h"

#define MAX_DIM 10

typedef struct{
    const Entity* rooms[MAX_DIM];
    int current_room;

    int dungeon;
    int target_entity;
    int target_count;
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