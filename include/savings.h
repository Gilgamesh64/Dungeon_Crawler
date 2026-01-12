#ifndef SAVINGS_H
#define SAVINGS_H



/**
 * Returns the name of the saving file
 * EX. savings2.txt, savings3.txt, savings10.txt; index = 3 puts into buf "savings3.txt"
 * @param buf to store the name
 * @param index of the file
 */
void get_file_name(char* buf, int index);

/**
 * Counts the number of files in the savings directory
 * @return the number of files in the 'savings' dir
 */
int count_files();

/**
 * EX. saving2, saving4, saving10. Returns 10
 * @return the index of the file with the highest count
 * @see get_file_name()
 */
int get_last_index();

/**
 * Returns the saving in the Nth position desc
 * EX saving2, saving4, saving10; n = 1, returns 4
 * @param n positon
 * @see get_file_name()
 * @see get_file_index()
 */
int get_nth_index(int n);

/**
 * Reads every save file and puts its content into a new array inside a buffer
 * @param buffers for the savings content
 * @see get_file_name()
 * @see read_inside()
 * @see get_last_index()
 */
void get_all_saves(char *buffers[]);

/**
 * @brief save using current game_data
 *
 * Creates a new saving file with index based on the last save file index
 */
void save();

/**
 * Loads savings
 * @param path to the savings file
 */
void load(const char* path);


#endif