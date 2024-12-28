#ifndef UTILS_H
#define UTILS_H

// Function to split a line into an array of strings based on a delimiter
char **split_line(const char *line, char delimiter, int *count);

// Function to join an array into a string based on a delimiter
char *join_line(char **line, const char delimiter, const long count);

#endif // UTILS_H