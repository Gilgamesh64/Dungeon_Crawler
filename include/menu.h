#ifndef MENU_H
#define MENU_H

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

#endif