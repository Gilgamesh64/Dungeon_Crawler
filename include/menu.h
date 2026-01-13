#ifndef MENU_H
#define MENU_H

#include <stdbool.h>

/**
 * main menu displayed at the start of the game
 */
void main_menu();
/**
 * inventory menu displaying current items and stats
 */
void save_menu();
/**
 * village menu displayed when in the village
 */
void village_menu();
/**
 * inventory menu to see stats and consume potions
 */
void inventory_menu();

/**
 * mission selection menu displayed when choosing a dungeon
 */
void mission_selection_menu();
/**
 * mission menu displayed when inside a dungeon, showing action options 
 */
void mission_menu();

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
 * shop menu managing the shop interactions
 */
void shop_menu();

/**
 * Checks if a number is in the Padovan sequence
 */
bool is_in_paduvan_sequence(int number);
/**
 * Plays rock paper scissors game
 */
bool shield_magic_sword(int player_choice);


#endif