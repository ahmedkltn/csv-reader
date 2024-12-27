#ifndef UTILS_H
#define UTILS_H

// Function to split a line into an array of strings based on a delimiter
char **split_line(const char *line, char delimiter, int *count);

// Function to read head of csv
void head_csv(const CSVFile *csv, const int lines);

// Function to trim leading and trailing whitespace from a string
char *trim_whitespace(char *str);

// Function to check if a cell value matches a condition
int match_condition(const char *cell, const char *condition);

#endif // UTILS_H