#include "item.h"
#include <stdio.h>


Item get_item(int pos_item){
    return items[pos_item];
}

bool has_item(int item_id){
    return (get_game_data()->items / item_id) % 10 != 0;
}
void set_item(int item_id){
    get_game_data() -> items += item_id;
}

long get_potions(){
    return (get_game_data()->items / POTION_ID);
}
void add_potion(){
    get_game_data() -> items += POTION_ID;
}
void sub_potion(){
    get_game_data() -> items -= POTION_ID;
}