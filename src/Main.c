#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    printf("Result: %d", roll_dice());
    printf("!!!\n");
    return 0;
}