#ifndef DATA_H
#define DATA_H

typedef struct {
    int health_points;
    int coins;
    int items;
    int missions_completed;
} GameData;

GameData *get_game_data(void);

void print_data();

#endif