#ifndef CSV_H
#define CSV_H

typedef struct
{
    char ***data;
    long row_count;
    long col_count;
} CSVFile;

// Function to read a CSV file
CSVFile *read_csv(const char *filename, const char sep);

// Function to read head of csv
void head_csv(const CSVFile *csv, const int from, const int to);

// Function to write a CSV file
void write_csv(const char *filename, CSVFile *csv, const char sep);

// Function to free allocated memory for CSVFile
void free_csv(CSVFile *csv);

#endif // CSV_H