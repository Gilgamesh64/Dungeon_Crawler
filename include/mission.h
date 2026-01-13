#ifndef MISSION_H
#define MISSION_H

#include "entity.h"

#define MAX_DIM 10

#define SWAMP_ID 0
#define MANSION_ID 1
#define CAVE_ID 2
#define BOSS_ID 3

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

/**
 * Updates the missions_completed variable and if possible unlocks the final mission
 */
void complete_mission(int mission_number);

/**
 * @return true if the mission with the given id has been completed
 */
bool has_completed(int mission_number);

#endif