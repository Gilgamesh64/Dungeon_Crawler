#ifndef DATA_H
#define DATA_H

#include <stddef.h>

typedef struct {
    int health_points;
    int coins;
    int items;
    int missions_completed;
} GameData;

GameData *get_game_data(void);

void save();
int load(const char* path);
void print_data();
int get_latest_filename(char *buffer, size_t size);

#endif