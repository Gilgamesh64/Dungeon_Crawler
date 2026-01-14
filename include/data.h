/**
 * @file data.h
 * @brief game data that needs to be serialized
 * @see savings to know how
 * 
 * @details
 * keeps useful info and allows public access to it
 */

#ifndef DATA_H
#define DATA_H

#define DEFAULT_HEALTH 20
#define DEFAULT_MONEY 0
#define DEFAULT_ITEMS 0
#define DEFAULT_QUESTS 0

typedef struct {
    int health_points;
    int coins;
    long items;
    int missions_completed;
} game_data_t;

/**
 * @return a pointer to the static game data object
 */
game_data_t *get_game_data(void);

/**
 * Resets game data to default
 */
void reset_data();

/**
 * Checks if player health is in bounds 0<health<=20 and if money is >= 0
 */
void data_control();

#endif