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
    
} GameData;

/**
 * Returns the pointer to the static game data object
 */
GameData *get_game_data(void);

/**
 * Prints current game data
 */
void print_data();

void reset_data();


/**
 * Checks if player health is in bounds 0<health<=20
 */
void health_control();

#endif