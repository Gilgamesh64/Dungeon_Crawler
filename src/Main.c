#include "utils.h"
#include "menu.h"
#include <stdlib.h>
#include <time.h>

int main(void){
    srand(time(NULL));
    clear_screen();
    
    main_menu();
    
    return 0;
}