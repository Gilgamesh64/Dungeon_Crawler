#include "item.h"


Item get_item(int pos_item){
    return items[pos_item];
}


bool has_sword(){
    return (get_game_data()->items / SWORD_POS) % 10 != 0;
}
void set_sword(){
    get_game_data() -> items += SWORD_POS;
}

bool has_armor(){
    return (get_game_data()->items / ARMOR_POS) % 10 != 0;
}
void set_armor(){
    get_game_data() -> items += ARMOR_POS;
}

bool has_key(){
    return (get_game_data()->items / KEY_POS) % 10 != 0;
}
void set_key(){
    get_game_data() -> items += KEY_POS;
}

bool has_hero_sword(){
    return (get_game_data()->items / HERO_SWORD_POS) % 10 != 0;
}
void set_hero_sword(){
    get_game_data() -> items += HERO_SWORD_POS;
}

int get_potions(){
    return (get_game_data()->items / POTION_POS);
}
void add_potion(){
    get_game_data() -> items += POTION_POS;
}
void sub_potion(){
    get_game_data() -> items -= POTION_POS;
}