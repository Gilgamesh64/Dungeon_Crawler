#ifndef MENU_H
#define MENU_H

#include <stdbool.h>

/**
 * main menu displayed at the start of the game
 */
void main_menu();

/**
 * main menu when cheats are unlocked
 */
void main_menu_cheats();

/**
 * village menu displayed when in the village
 */
void village_menu();

/**
 * mission selection menu displayed when choosing a dungeon
 */
void mission_selection_menu();

/**
 * mission menu displayed when inside a dungeon, showing action options 
 */
void mission_menu();

/**
 * inventory menu to see stats and consume potions
 */
void inventory_menu();

/**
 * shop menu managing the shop interactions
 */
void shop_menu();

/**
 * inventory menu displaying current items and stats
 */
void save_menu();

/**
 * room menu managing the interaction inside a room
 */
void room_menu();

/**
 * trap menu managing the messages when a trap is triggered
 */
void trap_menu();

/**
 * combat menu managing the combat nessages when combat is triggered
 */
void combat_menu();

/**
 * @return true if damage is not taken, false otherwise
 */
bool dragon_combat();

/**
 * Checks if a number is in the Padovan sequence
 * @param number to search
 * @return true if is in sequence
 */
bool is_in_paduvan_sequence(int number);

/**
 * Computes the n-th element of the Padovan sequence
 * @param n index of the element
 * @return value of the n-th element
 */
int padovan_element(int n);

/**
 * Checks if player has the armor
 * If yes, gives back 1 hp to player
 */
void apply_armor();


/**
 * Checks if player has sword or hero sword
 * @param room, if current enemy is 'Generale Orco' and player has hero sword you deal 1 additional damage
 * @return 0 if player has no sword
 * @return 1 if player has sword
 * @return 2 if player has hero sword
 * @return 3 if player has hero sword and room points to a 'Generale Orco'
 */
int apply_sword(int room);

/**
 * Final boss: castello del signore oscuro
 */
void boss_menu();

/**
 * Plays rock paper scissors game
 */
bool shield_magic_sword(int player_choice);



#endif