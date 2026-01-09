#include "item.h"


Item get_item(int pos_item){
    return items[pos_item];
}


bool has_sword(){
    return get_game_data()->items % 10 == 0;
}
void set_sword(){
    get_game_data() -> items += 1;
}

bool has_armor(){
    return (get_game_data()->items / 10) % 10 == 0;
}
void set_armor(){
    get_game_data() -> items += 10;
}


bool has_key(){
    return (get_game_data()->items / 100) % 10 == 0;
}
void set_key(){
    get_game_data() -> items += 100;
}

bool has_hero_sword(){
    return (get_game_data()->items / 1000) % 10 == 0;
}
void set_hero_sword(){
    get_game_data() -> items += 1000;
}

int get_potions(){
    return (get_game_data()->items / 10000);
}
void add_potion(){
    get_game_data() -> items += 10000;
}
void sub_potion(){
    get_game_data() -> items -= 10000;
}