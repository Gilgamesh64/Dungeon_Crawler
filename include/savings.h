#ifndef SAVINGS_H
#define SAVINGS_H

#define MAX_FILES 100 //MAX NUMBER OF SAVINGS
#define MAX_LINE 1024 //MAX SAVING LINE LENGHT

void save();
void load(const char* path);
int get_last_index();
void get_file_name(char* buf, int index);
int get_all_saves(char *buffers[]);
int get_nth_index(int n);


#endif