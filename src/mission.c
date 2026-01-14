#include "mission.h"
#include "utils.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void generate_dungeon(int current_level) {
    dungeon.current_room = 0;
    dungeon.dungeon_id = current_level;

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
            dungeon.rooms[i] = get_entity(current_level, dungeon.target_entity);
        }

        if(!strcmp(dungeon.rooms[i]->name, get_entity(current_level, dungeon.target_entity)->name)){
            count--;
        }
    }
}

bool is_boss_unlocked_cheating = false;

void complete_mission(const int mission_number){
    get_game_data() -> missions_completed += pow(10, mission_number);
}

bool has_completed(const int mission_number){
    return (get_game_data() -> missions_completed / (int) pow(10, mission_number)) % 10;
}

bool is_final_mission_unlocked(){
    return (has_completed(SWAMP_ID) && has_completed(MANSION_ID) && has_completed(CAVE_ID)) || is_boss_unlocked_cheating;
}

char* get_mission_name(int mission_number){
    switch (mission_number){
    case SWAMP_ID:
        return "Palude Putrescente";
        break;
    case MANSION_ID:
        return "Magione Infestata";
        break;
    case CAVE_ID:
        return "Caverna di Cristallo";
        break;
    case BOSS_ID:
        return "Castello del signore Oscuro";
        break;
    
    default:
        break;
    }
    return "";
}

dungeon_t *get_dungeon() {
    return &dungeon;
}