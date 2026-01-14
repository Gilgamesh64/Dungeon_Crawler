#include "data.h"
#include "entity.h"
#include "item.h"
#include "utils.h"
#include "menu.h"
#include <stdio.h>


game_data_t *get_game_data(void) {
    static game_data_t data = {DEFAULT_HEALTH, DEFAULT_MONEY, DEFAULT_ITEMS, DEFAULT_QUESTS};
    return &data;
}

void data_control(){
    game_data_t* data = get_game_data();

    if(data -> coins < 0) data -> coins = 0; 
    if(data->health_points>20) data->health_points = 20;
    
    if(data->health_points <= 0){
        click_to_continue("\nGAME OVER!\n");
        reset_data();
        main_menu();
    }
}

void reset_data(){
    game_data_t* data = get_game_data();
    data -> health_points = DEFAULT_HEALTH;
    data -> coins = DEFAULT_MONEY;
    data -> items = DEFAULT_ITEMS;
    data -> missions_completed = DEFAULT_QUESTS;
}