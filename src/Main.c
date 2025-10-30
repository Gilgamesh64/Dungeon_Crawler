#include "utils.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    clear_screen();
    printf("Result: %d\n", roll_dice());

    char* name = get_string("Insert the name of the player: ");
    printf("%s\n", name);

    clear_screen();

    main_menu();
    
    return 0;
}