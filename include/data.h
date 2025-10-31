#ifndef DATA_H
#define DATA_H

#include <stddef.h>

#define MAX_FILES 100
#define MAX_LINE 1024

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
int get_last_index();
void get_file_name(char* buf, int index);
int get_all_saves(char *buffers[]);
int delete(const char *path);
int get_nth_index(int n);

#endif