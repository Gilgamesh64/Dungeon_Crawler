#ifndef SAVINGS_H
#define SAVINGS_H

void save();
void load(const char* path);
int get_last_index();
void get_file_name(char* buf, int index);
void get_all_saves(char *buffers[]);
int get_nth_index(int n);
int count_files();


#endif