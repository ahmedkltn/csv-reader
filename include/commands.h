#ifndef COMMANDS_H
#define COMMANDS_H

#include "csv.h"

// Function to search rows based on a query
void search_csv(CSVFile *csv, const char *query);

// Function to add a new row to the CSV
void add_row(CSVFile *csv);

// Function to delete rows based on a query
void delete_row(CSVFile *csv, const char *query);

#endif // COMMANDS_H