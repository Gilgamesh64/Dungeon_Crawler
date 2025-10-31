#include "data.h"
#include "menu.h"
#include <stdio.h>

GameData *get_game_data(void) {
    static GameData data = {20, 0, 0, 0};
    return &data;
}

static void get_next_filename(char *buffer, size_t size) {
    int i = 1;
    FILE *f;

    do {
        snprintf(buffer, size, "saving%d.txt", i);
        f = fopen(buffer, "r");
        if (f) {
            fclose(f);
            i++;
        } else {
            break;
        }
    } while (1);
}


int get_latest_filename(char *buffer, size_t size) {
    int i = 1;
    FILE *f;

    while (1) {
        snprintf(buffer, size, "saving%d.txt", i);
        f = fopen(buffer, "r");
        if (!f) {
            // No file with this number → last existing is i-1
            if (i == 1) return 0; // No saves exist
            snprintf(buffer, size, "saving%d.txt", i - 1);
            return 1;
        }
        fclose(f);
        i++;
    }
}



void save() {

    char filename[64];
    get_next_filename(filename, sizeof(filename));

    FILE *f = fopen(filename, "w");
    if (!f) return;

    GameData *s = get_game_data();

    fprintf(f, "%d P.VITA , %d MONETE , %d OGGETTI , %d MISSIONI COMPLETATE\n",
            s->health_points,
            s->coins,
            s->items,
            s->missions_completed);

    fclose(f);
}


int load(const char* path) {
    FILE *f = fopen(path, "r");
    if (!f) return 1;

    GameData *s = get_game_data();

    fscanf(f, "%d P.VITA , %d MONETE , %d OGGETTI , %d MISSIONI COMPLETATE",
           &s->health_points,
           &s->coins,
           &s->items,
           &s->missions_completed);

    fclose(f);
    return 0;
}


void print_data(){
    GameData *s = get_game_data();

    printf("%d P.VITA , %d MONETE , %d OGGETTI , %d MISSIONI COMPLETATE",
            s->health_points,
            s->coins,
            s->items,
            s->missions_completed);

}