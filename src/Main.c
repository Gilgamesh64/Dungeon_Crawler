#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    printf("Result: %d\n", roll_dice());

    click_to_continue("Click to continue\n");

    char* name = get_string("Insert the name of the player: ");
    printf("%s\n", name);

    clear_screen();

    char buf[100];
    get_string_buffer(buf, sizeof(buf), "Insert Something: ");
    printf("%s\n", buf);
    
    return 0;
}