#ifndef ENTITY_H
#define ENTITY_H

typedef struct{
    char* name;
    int fatal;
    int damage;
    int coins;
    int trap;
} Entity;

static const Entity PALUDE_PUTRESCENTE[6] = {
    { "Cane Selvaggio",      4,   15,  5, 0 },
    { "Goblin",              3,   12,  4, 0 },
    { "Scheletro",           5,   20,  3, 0 },
    { "Orco",                8,   35,  2, 0 },
    { "Acquitrino Velenoso", 0,    0,  0, 1 },
    { "Generale Orco",      12,   50,  3, 0 }
};

static const Entity MAGIONE_INFESTATA[6] = {
    { "Botola Buia",         0,    0,  0, 1 },
    { "Pipistrello",         2,    8,  8, 0 },
    { "Zombie",              4,   30,  1, 0 },
    { "Fantasma",            6,   25,  7, 0 },
    { "Vampiro Superiore",  10,   60,  6, 0 },
    { "Demone Custode",     15,   80,  4, 0 }
};

static const Entity GROTTA_DI_CRISTALLO[6] = {
    { "Stanza Vuota",         0,    0,  0, 0 },
    { "Cristalli Cadenti",    0,    0,  0, 1 },
    { "Ponte Pericolante",    0,    0,  0, 1 },
    { "Forziere Misterioso",  0,    0,  0, 1 },
    { "Rupe Scoscesa",        0,    0,  0, 1 },
    { "Drago Antico",       25,  250,  5, 0 }
};

static const Entity* LEVEL_TABLE[] = {
    PALUDE_PUTRESCENTE,
    MAGIONE_INFESTATA,
    GROTTA_DI_CRISTALLO
};

#define LEVEL_COUNT (sizeof(LEVEL_TABLE) / sizeof(LEVEL_TABLE[0]))


Entity spawn_entity(int current_level);


#endif