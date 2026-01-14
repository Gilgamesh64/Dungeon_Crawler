#include "savings.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include "dirent.h"
#else
#include <dirent.h>
#endif

void get_file_name(char *buf, int index) {
    sprintf(buf, "savings/saving%d.txt", index);
}

/**
 * EX. savings2.txt, savings3.txt, savings10.txt; filename = "savings3.txt" returns 3
 * @return the index of the file
 * @param filename to search
 */
int get_file_index(const char *filename) {
    int index = -1;
    sscanf(filename, "savings/saving%d.txt", &index);

    return index;
}


int count_files() {
    DIR *dir = opendir("savings");
    int file_count = 0;

    if (dir == NULL) {
        printf("Error opening 'savings' folder, please create one");
        return -1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (entry->d_name[0] == '.' &&
            (entry->d_name[1] == '\0' ||
             (entry->d_name[1] == '.' && entry->d_name[2] == '\0')))
            continue;

        file_count++;
    }

    closedir(dir);
    return file_count;
}


int get_last_index() {
    char filename[256];
    int found = 0;
    int last_index = 0;
    int file_number = count_files();

    for (int i = 0; found < file_number; i++) {

        get_file_name(filename, i);

        FILE *file = fopen(filename, "r");
        if (file) {
            fclose(file);
            found++;
            last_index = i;
        }
    }
    return last_index;
}


int get_nth_index(int n) {
    int count = 0;

    for (int i = get_last_index(); i >= 0; i--) {
        char filename[256];
        get_file_name(filename, i);

        FILE *f = fopen(filename, "r");
        if (!f)
            continue;
        fclose(f);

        count++;
        if (count == n) {
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
        printf("Failed to open file");
        return;
    }

    if (!fgets(buf, bufsize, file)) {
        fclose(file);
        return;
    }
    fclose(file);

    buf[strcspn(buf, "\n")] = '\0';
}


void get_all_saves(char *buffers[]) {
    char filename[256];
    int found = 0;
    int file_count = count_files();

    for (int i = get_last_index(); found < file_count; i--) {
        get_file_name(filename, i);

        FILE *f = fopen(filename, "r");
        if (!f)
            continue;
        fclose(f);

        read_inside(filename, buffers[found], 256);

        found++;
    }
}

void save() {
    char filename[256];

    get_file_name(filename, get_last_index() + 1);

    FILE *f = fopen(filename, "w");
    if (!f)
        return;

    game_data_t *s = get_game_data();

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    char date_str[11];
    char time_str[9];

    strftime(date_str, sizeof(date_str), "%d/%m/%Y", t);
    strftime(time_str, sizeof(time_str), "%H:%M:%S", t);

    fprintf(f, "%s DATA , %s ORA , %d P.VITA , %d MONETE , %d OGGETTI , %d MISSIONI COMPLETATE\n",
            date_str,
            time_str,
            s->health_points,
            s->coins,
            s->items,
            s->missions_completed);

    fclose(f);
}


void load(const char *path) {
    FILE *f = fopen(path, "r");
    if (!f)
        return;

    game_data_t *data = get_game_data();
    char line[256];
    fgets(line, sizeof line, f);

    printf("%s\n", line);

    sscanf(line,
           "%*s DATA , %*s ORA , %d P.VITA , %d MONETE , %d OGGETTI , %d MISSIONI COMPLETATE",
           &data->health_points,
           &data->coins,
           &data->items,
           &data->missions_completed);

    fclose(f);
    return;
}
