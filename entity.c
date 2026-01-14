#include "entity.h"
#include "utils.h"
#include <stdio.h>

/**
 * current level is the index in the main array
 * the other index is the entity spawned randomly
 */
Entity* spawn_entity(int current_level){
    return &LEVEL_TABLE[current_level][roll_dice()-1];
}
