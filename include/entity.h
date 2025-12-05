#ifndef ENTITY_H
#define ENTITY_H

#include <stdbool.h>

/**
 * struct defining an entity, which could be either an enemy or a trap
 */
typedef struct{
    const char* name;
    const int fatal;
    const int damage;
    const int coins;
    const bool trap;
} Entity;


/**
 * Arrays of entities, one for room
 * Each one contains an Entity
 * Their index in the array is the die roll required to spawn them -1
 */

/** Le trappole hanno l'attributo "fatal" che classifica le loro meccaniche particolari
 * fatal = 0 ---> nessuna meccanica extra
 * fatal = 1 ---> randomizzazione danno
 * fatal = 2 ---> coin flip
 * perché proprio l'attributo fatal? perché non veniva usato nelle trappole :3
 * */

static const Entity PALUDE_PUTRESCENTE[6] = {
    {
        .name  = "Cane Selvaggio",
        .fatal = 2,
        .damage = 1,
        .coins = 0,
        .trap = false
    },
    {
        .name  = "Goblin",
        .fatal = 3,
        .damage = 2,
        .coins = 2,
        .trap = false
    },
    {
        .name  = "Scheletro",
        .fatal = 4,
        .damage = 2,
        .coins = 4,
        .trap = false
    },
    {
        .name  = "Orco",
        .fatal = 3,
        .damage = 4,
        .coins = 6,
        .trap = false
    },
    {
        .name  = "Acquitrino Velenoso",
        .fatal = 1,
        .damage = 0,
        .coins = 0,
        .trap = true
    },
    {
        .name  = "Generale Orco",
        .fatal = 6,
        .damage = 3,
        .coins = 12,
        .trap = false
    }
};

static const Entity MAGIONE_INFESTATA[6] = {
    {
        .name  = "Botola Buia",
        .fatal = 0,
        .damage = 3,
        .coins = 0,
        .trap = true
    },
    {
        .name  = "Pipistrello",
        .fatal = 2,
        .damage = 2,
        .coins = 1,
        .trap = false
    },
    {
        .name  = "Zombie",
        .fatal = 3,
        .damage = 2,
        .coins = 2,
        .trap = false
    },
    {
        .name  = "Fantasma",
        .fatal = 5,
        .damage = 2,
        .coins = 4,
        .trap = false
    },
    {
        .name  = "Vampiro Superiore",
        .fatal = 4,
        .damage = 4,
        .coins = 7,
        .trap = false
    },
    {
        .name  = "Demone Custode",
        .fatal = 4,
        .damage = 6,
        .coins = 10,
        .trap = false
    }
};

static const Entity GROTTA_DI_CRISTALLO[6] = {
    {
        .name  = "Stanza Vuota",
        .fatal = 0,
        .damage = 0,
        .coins = 0,
        .trap = false
    },
    {
        .name  = "Cristalli Cadenti",
        .fatal = 0,
        .damage = 2,
        .coins = 0,
        .trap = true
    },
    {
        .name  = "Ponte Pericolante",
        .fatal = 0,
        .damage = 0,
        .coins = -3,
        .trap = true
    },
    {
        .name  = "Forziere Misterioso",
        .fatal = 2,
        .damage = 2,
        .coins = 10,
        .trap = true
    },
    {
        .name  = "Rupe Scoscesa",
        .fatal = 1,
        .damage = 0,
        .coins = 0,
        .trap = true
    },
    {
        .name  = "Drago Antico",
        .fatal = 5,
        .damage = 10,
        .coins = 12,
        .trap = false
    }
};

/**
 * Array of missions, each index is a mission
 * Each index in a mission is an enemy
 */
static const Entity* LEVEL_TABLE[] = {
    PALUDE_PUTRESCENTE,
    MAGIONE_INFESTATA,
    GROTTA_DI_CRISTALLO
};

/**
 * Spawns an Entity from the given mission
 */
Entity spawn_entity(int current_level);


#endif