#include "entity.h"
#include "utils.h"
#include <stdio.h>


entity_t* spawn_entity(int current_level){
    return &LEVEL_TABLE[current_level][roll_dice()-1];
}

entity_t* get_entity(int level, int entity_id){
    return &LEVEL_TABLE[level][entity_id];
}