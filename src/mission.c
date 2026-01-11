#include "mission.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void generate_dungeon(int current_level) {
    dungeon.current_room = 0;
    dungeon.dungeon = current_level;

    switch (current_level) {
    case 0:
        dungeon.target_count = 3;
        dungeon.target_entity = 5;

        break;
    case 1:
        dungeon.target_count = 1;
        dungeon.target_entity = 4;
        break;

    case 2:
        dungeon.target_count = 1;
        dungeon.target_entity = 5;

        break;

    default:
        break;
    }

    int count = dungeon.target_count;

    for(int i = 0; i < MAX_DIM; i++){
        if(i + count < MAX_DIM) {
            dungeon.rooms[i] = spawn_entity(current_level);
        } else {
            dungeon.rooms[i] = &LEVEL_TABLE[current_level][dungeon.target_entity];
        }

        if(!strcmp(dungeon.rooms[i]->name, (&LEVEL_TABLE[current_level][dungeon.target_entity])->name)){
            count--;
        }
    }
}

Dungeon *get_dungeon() {
    return &dungeon;
}