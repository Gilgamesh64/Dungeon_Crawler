#ifndef DATA_H
#define DATA_H

#define DEFAULT_HEALTH 20
#define DEFAULT_MONEY 0
#define DEFAULT_ITEMS 0
#define DEFAULT_QUESTS 0

typedef struct {
    int health_points;
    int coins;
    int items;
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

#endif