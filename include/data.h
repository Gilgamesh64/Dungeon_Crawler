#ifndef DATA_H
#define DATA_H

#define DEFAULT_HEALTH 20
#define DEFAULT_MONEY 0
#define DEFAULT_ITEMS 0
#define DEFAULT_QUESTS 0
#define DIM_DUNGEON 10

#include "entity.h"



typedef struct {
    int health_points;
    int coins;
    int items;
    int missions_completed;
    int current_rooms;
    int dungeon_id;
    
    Entity dungeonAttuale[DIM_DUNGEON];
    
} GameData;

void generate_dungeon(int current_level);

GameData *get_game_data(void);

void print_data();

#endif