#ifndef MISSION_H
#define MISSION_H

#include "entity.h"

#define MAX_DIM 10

#define SWAMP_ID 0
#define MANSION_ID 1
#define CAVE_ID 2
#define BOSS_ID 3

/**
 * Set to true with cheats
 */
extern bool is_boss_unlocked_cheating;

typedef struct{
    entity_t* rooms[MAX_DIM];
    int current_room;

    int dungeon_id;
    int target_entity;
    int target_count;
} dungeon_t;

static dungeon_t dungeon;

/**
 * Generates a dungeon for the current level
 * @param current_level index of the current level
 */
void generate_dungeon(int current_level);

/**
 * @return the current dungeon
 */
dungeon_t* get_dungeon();

/**
 * Updates the missions_completed variable and if possible unlocks the final mission
 * @param mission_number to set
 * @see defined constants
 */
void complete_mission(const int mission_number);

/**
 * @param mission_number of the mission
 * @see defined constants
 * @return true if the mission has been completed
 */
bool has_completed(const int mission_number);

/**
 * @return true if the final mission has been unlocked
 */
bool is_final_mission_unlocked();

/**
 * @param mission_number
 * @see defined constants
 * @return the name of the mission
 */
char* get_mission_name(int mission_number);

#endif