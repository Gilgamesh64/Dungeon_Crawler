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
} entity_t;


/**
 * Arrays of entities, one for each room
 * Each entry contains an entity_t
 * Their index in the array is the die roll required to spawn them -1
 */

/**Traps "fatal" attribute classifies special mechanics
 * fatal = 0 ---> nothing
 * fatal = 1 ---> random damage
 * fatal = 2 ---> coin flip
 * */

static entity_t PALUDE_PUTRESCENTE[6] = {
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

static entity_t MAGIONE_INFESTATA[6] = {
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

static entity_t GROTTA_DI_CRISTALLO[6] = {
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
static entity_t* LEVEL_TABLE[] = {
    PALUDE_PUTRESCENTE,
    MAGIONE_INFESTATA,
    GROTTA_DI_CRISTALLO
};

/**
 * @param current_level is the index in the mission array
 * the other index is the entity spawned randomly
 * @return a pointer to a random entity of the given level
 */
entity_t* spawn_entity(int current_level);

/**
 * @param level id of the level
 * @param entity_id id of the entity
 * @return the entity with the correct id in the specified level
 */
entity_t* get_entity(int level, int entity_id);


#endif