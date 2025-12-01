#ifndef ENTITY_H
#define ENTITY_H

typedef struct{
    const char* name;
    int fatal;
    int damage;
    int coins;
    int trap;
} Entity;

static const Entity PALUDE_PUTRESCENTE[6] = {
    {
        .name  = "Cane Selvaggio",
        .fatal = 4,
        .damage = 15,
        .coins = 5,
        .trap = 0
    },
    {
        .name  = "Goblin",
        .fatal = 3,
        .damage = 12,
        .coins = 4,
        .trap = 0
    },
    {
        .name  = "Scheletro",
        .fatal = 5,
        .damage = 20,
        .coins = 3,
        .trap = 0
    },
    {
        .name  = "Orco",
        .fatal = 8,
        .damage = 35,
        .coins = 2,
        .trap = 0
    },
    {
        .name  = "Acquitrino Velenoso",
        .fatal = 0,
        .damage = 0,
        .coins = 0,
        .trap = 1
    },
    {
        .name  = "Generale Orco",
        .fatal = 12,
        .damage = 50,
        .coins = 3,
        .trap = 0
    }
};

static const Entity MAGIONE_INFESTATA[6] = {
    {
        .name  = "Botola Buia",
        .fatal = 0,
        .damage = 0,
        .coins = 0,
        .trap = 1
    },
    {
        .name  = "Pipistrello",
        .fatal = 2,
        .damage = 8,
        .coins = 8,
        .trap = 0
    },
    {
        .name  = "Zombie",
        .fatal = 4,
        .damage = 30,
        .coins = 1,
        .trap = 0
    },
    {
        .name  = "Fantasma",
        .fatal = 6,
        .damage = 25,
        .coins = 7,
        .trap = 0
    },
    {
        .name  = "Vampiro Superiore",
        .fatal = 10,
        .damage = 60,
        .coins = 6,
        .trap = 0
    },
    {
        .name  = "Demone Custode",
        .fatal = 15,
        .damage = 80,
        .coins = 4,
        .trap = 0
    }
};

static const Entity GROTTA_DI_CRISTALLO[6] = {
    {
        .name  = "Stanza Vuota",
        .fatal = 0,
        .damage = 0,
        .coins = 0,
        .trap = 0
    },
    {
        .name  = "Cristalli Cadenti",
        .fatal = 0,
        .damage = 0,
        .coins = 0,
        .trap = 1
    },
    {
        .name  = "Ponte Pericolante",
        .fatal = 0,
        .damage = 0,
        .coins = 0,
        .trap = 1
    },
    {
        .name  = "Forziere Misterioso",
        .fatal = 0,
        .damage = 0,
        .coins = 0,
        .trap = 1
    },
    {
        .name  = "Rupe Scoscesa",
        .fatal = 0,
        .damage = 0,
        .coins = 0,
        .trap = 1
    },
    {
        .name  = "Drago Antico",
        .fatal = 25,
        .damage = 250,
        .coins = 5,
        .trap = 0
    }
};


static const Entity* LEVEL_TABLE[] = {
    PALUDE_PUTRESCENTE,
    MAGIONE_INFESTATA,
    GROTTA_DI_CRISTALLO
};

Entity spawn_entity(int current_level);

#endif