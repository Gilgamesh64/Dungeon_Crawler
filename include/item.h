#ifndef ITEM_H
#define ITEM_H

#include "data.h"
#include <stdbool.h>

#define NUM_ITEMS 5

#define SWORD_POS 1
#define ARMOR_POS 10
#define KEY_POS 100
#define HERO_SWORD_POS 1000
#define POTION_POS 10000

typedef struct{
    const char* name;
    const char* description;
    const int cost;
} Item;

Item get_item(int);

/**
 * Returns true if the player has the sword
 */
bool has_sword();
/**
 * Sets the player as having the sword
 */
void set_sword();

/**
 * Returns true if the player has the armor
 */
bool has_armor();
/**
 * Sets the player as having the armor
 */
void set_armor();

/**
 * Returns true if the player has the last level key
 */
bool has_key();
/**
 * Sets the player as having the last level key
 */
void set_key();

/**
 * Returns true if the player has the hero sword
 */
bool has_hero_sword();
/**
 * Sets the player as having the hero sword
 */
void set_hero_sword();

/**
 * Returns the number of potions the player has
 */
int get_potions();
/**
 * Adds 1 potion to the player's inventory
 */
void add_potion();
/**
 * Subtracts 1 potion from the player's inventory
 */
void sub_potion();

static const  Item items[NUM_ITEMS]  = {
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