#ifndef ITEM_H
#define ITEM_H


#define NUM_ITEMS 5

typedef struct{
    const char* name;
    const char* description;
    const int cost;
} Item;

Item get_item(int);

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