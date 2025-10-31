#include "data.h"
#include "menu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

GameData *get_game_data(void) {
    static GameData data = {20, 0, 0, 0};
    return &data;
}

/**
 * Returns the name of the saving file 
 * EX. savings2.txt, savings3.txt, savings10.txt; index = 3 puts into buf "savings3.txt"
 * @param buf to store the name
 * @param index of the file
 */
void get_file_name(char* buf, int index){
    sprintf(buf, "saving%d.txt", index);
}

/**
 * Returns the index of the file 
 * EX. savings2.txt, savings3.txt, savings10.txt; filename = "savings3.txt" returns 3
 * @param filename to search
 */
int get_file_index(const char *filename) {
    int index = -1;
    sscanf(filename, "saving%d.txt", &index);
    
    return index;
}


/**
 * Returns the index of the file with the highest count
 * EX. saving2, saving4, saving10. Returns 10
 */
int get_last_index() {
    char filename[256];

    for (int i = MAX_FILES; i >= 0; --i) {
        get_file_name(filename, i);

        FILE *file = fopen(filename, "r");
        if (file) {
            fclose(file);
            return i;
        }
    }
    return 0;
}

/**
 * Returns the saving in the Nth position desc
 * EX saving2, saving4, saving10; n = 1, returns 4
 * @param n positon
 */
int get_nth_index(int n) {
    int count = 0;

    for (int i = get_last_index(); i >= 0; i--) {
        char filename[256];
        get_file_name(filename, i);

        FILE *f = fopen(filename, "r");
        if (!f) continue;
        fclose(f);

        count++;
        if (count == n){
            return get_file_index(filename);
        } 
    }
    return -1;
}


/**
 * Reads inside a file and puts its content into a buffer
 * @param path to the file
 * @param buf
 * @param bufsize
 */
void read_inside(const char *path, char *buf, size_t bufsize) {
    FILE *file = fopen(path, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    if (!fgets(buf, bufsize, file)) {
        fclose(file);
        return;
    }
    fclose(file);

    buf[strcspn(buf, "\n")] = '\0';
}

/**
 * Reads every save file and puts its content into a new array inside a buffer
 * @param buffers for the savings content
 */
int get_all_saves(char *buffers[]) {
    char filename[256];
    int count = 0;

    for (int i = get_last_index(); i >= 0 && count <= get_last_index(); i--) {
        get_file_name(filename, i);

        FILE *f = fopen(filename, "r");
        if (!f) continue;
        fclose(f);

        read_inside(filename, buffers[count], MAX_LINE);
        count++;
    }
    return count;
}

/**
 * Save using current game_data
 */
void save() {
    char filename[100];

    get_file_name(filename, get_last_index() + 1);
    
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


/**
 * Loads savings
 * @param path to the savings file
 */
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

/**
 * Prints current game_data
 */
void print_data(){
    GameData *s = get_game_data();

    printf("%d P.VITA , %d MONETE , %d OGGETTI , %d MISSIONI COMPLETATE",
            s->health_points,
            s->coins,
            s->items,
            s->missions_completed);
}