/**
 * @file mission.h
 * @brief handles missions and their completion
 * 
 * @details
 * Each mission has its associated value that is power of ten.
 * 
 * @see savings.h In save files, missions are stored as a single integer value.
 * @see item.h that uses a similar method
 * 
 * How? Well...
 * 
 * Save value: 101
 * 
 * Starting from the right, each digit represents the binary completion state
 * of a mission (1 = completed, 0 = not completed).
 * 
 * For example, the mission 'Palude Putrescente' has an ID of 0.
 * We can get the index value by calculating 10^0 = 1 
 * Since the first digit from right to left is 1, the player completed the mission.
 * 
 * The value is retrieved using the modulo ('%') operator.
 * 
 * 'Magione Infestata' has an ID of 1. 
 * The index value is 10^1 = 10 
 * Dividing 101 by 10 gives 10.
 * Taking the modulo of this result gives 0, meaning this mission is not completed.
 * 
 * Each mission is associated with 10 at specific power from 0 to x. Dividing the save
 * value by 10 ^ n and applying modulo allows us to determine mission completion.
 */

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