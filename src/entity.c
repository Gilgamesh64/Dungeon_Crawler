#include "entity.h"
#include "utils.h"
#include <stdio.h>

Entity spawn_entity(int current_level){
    return LEVEL_TABLE[current_level][roll_dice()-1];
}
