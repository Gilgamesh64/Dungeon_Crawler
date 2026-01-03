#ifndef ITEM_H
#define ITEM_H
#endif

const int NUM_ITEMS_GIOCO = 5; // numero di items presenti nel gioco



typedef struct{
    const char* name;
    const char* descrizione;
    const int costo;
} Item;

Item get_item(int);

static const  Item items[NUM_ITEMS_GIOCO]  = {
    {
        .name = "Pozione Curativa",
        .descrizione = "ripristina fino a 6 PUNTI VITA (lancia un dado a 6 facce)",
        .costo = 4
    },
    {
        .name = "Spada",
        .descrizione = "+1 all'attacco dell'eroe (acquistabile una sola volta)",
        .costo = 5
    },
    {
        .name = "Armatura",
        .descrizione = "-1 al Danno del nemico/trappola (acquistabile una sola volta)",
        .costo = 10
    },
    {
        .name = "Chiave del castello del SIGNORE OSCURO",
        .descrizione = "permette all'eroe di accedere al castello del SIGNORE OSCURO",
        .costo = -1
    },
    {
        .name = "SPADA DELL'EROE",
        .descrizione = "+1 all'attacco dell'eroe",
        .costo = -1
    }
};
