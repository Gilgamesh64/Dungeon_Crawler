/**
 * @file item.h
 * @brief handles items and collectibles
 * 
 * @details
 * Each item has its associated value that is power of ten.
 * 
 * @see savings.h In save files, items are stored as a single integer value.
 * @see mission.h that uses a similar method
 * 
 * How? Well...
 * 
 * Save value: 1250101
 * 
 * Starting from the right, each digit represents the binary possession state
 * of an item (1 = owned, 0 = not owned).
 * 
 * For example, the item 'SWORD' has an ID of 1. Since the first digit from
 * right to left is 1, the player owns the sword.
 * 
 * The value is retrieved using the modulo ('%') operator.
 * 
 * The armor item has an ID of 10. Dividing 1250101 by 10 gives 125010.
 * Taking the modulo of this result gives 0, meaning no armor is owned.
 * 
 * Each item is associated with a specific power of 10. Dividing the save
 * value by that power and applying modulo allows us to determine ownership.
 * 
 * What about potions? They do not have a binary value, they are stackable
 * Dividing 1250101 by 10000 gives 125, which represents the number of potions.
 * To add a potion, simply add 10000 to the save value.
 * 
 * With this method we can represent many non stackable items and one stackable item using just a single integer
 */

#ifndef ITEM_H
#define ITEM_H

#include "data.h"
#include <stdbool.h>

#define NUM_ITEMS 5

#define SWORD_ID 1
#define ARMOR_ID 10
#define KEY_ID 100
#define HERO_SWORD_ID 1000
#define POTION_ID 10000

typedef struct{
    const char* name;
    const char* description;
    const int cost;
} item_t;

/**
 * @param pos_item
 * @return the item at the position in the array
 */
item_t get_item(int pos_item);

/**
 * @param item_id
 * @return true if player has item
 */
bool has_item(int item_id);

/**
 * Gives the item to the player
 * @param item_id
 */
void set_item(int item_id);

/**
 * Returns the number of potions the player has
 */
long get_potions();
/**
 * Adds 1 potion to the player's inventory
 */
void add_potion();
/**
 * Subtracts 1 potion from the player's inventory
 */
void sub_potion();

static const item_t items[NUM_ITEMS]  = {
    {
        .name = "Pozione Curativa",
        .description = "ripristina fino a 6 PUNTI VITA (lancia un dado a 6 facce)",
        .cost = 4
    },
    {
        .name = "Spada",
        .description = "+1 all'attacco dell'eroe (acquistabile una sola volta)",
        .cost = 5
    },
    {
        .name = "Armatura",
        .description = "-1 al Danno del nemico/trappola (acquistabile una sola volta)",
        .cost = 10
    },
    {
        .name = "Chiave del castello del SIGNORE OSCURO",
        .description = "permette all'eroe di accedere al castello del SIGNORE OSCURO",
        .cost = -1
    },
    {
        .name = "SPADA DELL'EROE",
        .description = "+1 all'attacco dell'eroe",
        .cost = -1
    }
};

#endif