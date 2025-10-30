#include "utils.h"
#include <stdlib.h>

int roll_dice(void) {
    return (rand() % DICE_SIDES) + 1;
}