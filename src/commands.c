#include <commands.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
void add_row(CSVFile *csv)
{
    char *s = NULL;
    size_t buffsize;

    // reallocate memory for new row
    csv->data = realloc(csv->data, (csv->row_count + 1) * sizeof(char **));
    // allocate line for the new row
    // where line is an array
    csv->data[csv->row_count] = malloc((csv->col_count - 1) * sizeof(char *));

    // clear buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    for (int j = 0; j < csv->col_count - 1; j++)
    {
        buffsize = 0;
        printf("Provide value for the column %s : ", csv->data[0][j]);
        getline(&s, &buffsize, stdin);

        s[strcspn(s, "\n")] = '\0';
        // allocate a string
        // copy the value of s to the element of the line
        csv->data[csv->row_count][j] = malloc(strlen(s) * sizeof(char));
        csv->data[csv->row_count][j] = strdup(s);
    }
    free(s);
    csv->row_count++;
}

void search_csv(CSVFile *csv, const char *query)
{
    int count;
    int columnIndex = -1;
    int rowIndex = -1;
    // split the query by the =
    char **splittedQuery = split_line(query, '=', &count);

    char *column = splittedQuery[0];
    char *filtre = splittedQuery[1];

    // search for the index of column
    for (int i = 0; i < csv->col_count - 1; i++)
    {
        if (strcmp(csv->data[0][i], column) == 0)
        {
            columnIndex = i;
            break;
        }
    }
    if (columnIndex == -1)
    {
        printf("Column not found: %s\n", column);
        return;
    }
    for (int i = 0; i < csv->row_count; i++)
    {
        if (strcmp(csv->data[i][columnIndex], filtre) == 0)
        {
            rowIndex = i;
            break;
        }
    }
    if (columnIndex == -1)
    {
        printf("No matching row found for filter: %s\n", column);
        return;
    }
    printf("Result : \n");
    for (int i = 0; i < csv->col_count - 1; i++)
    {
        printf("\t%s", csv->data[rowIndex][i]);
    }
    free(splittedQuery);
    printf("\n");
    printf("\t\n\n");
}

long delete_row(CSVFile *csv, const char *query)
{
    int count;
    int columnIndex = -1;
    int rowIndex = -1;

    // Split the query by the '='
    char **splittedQuery = split_line(query, '=', &count);

    char *column = splittedQuery[0];
    char *filter = splittedQuery[1];

    // Search for the index of the column
    for (int i = 0; i < csv->col_count; i++)
    {
        if (strcmp(csv->data[0][i], column) == 0)
        {
            columnIndex = i;
            break;
        }
    }

    if (columnIndex == -1)
    {
        printf("Column not found: %s\n", column);
        return;
    }

    // Search for the row that matches the filter
    for (int i = 1; i < csv->row_count; i++)
    {
        if (strcmp(csv->data[i][columnIndex], filter) == 0)
        {
            rowIndex = i;
            break;
        }
    }

    if (rowIndex == -1)
    {
        fprintf(stderr, "No matching row found for filter: %s\n", filter);
        return;
    }

    // Free the memory for the deleted row
    for (int j = 0; j < csv->col_count; j++)
    {
        free(csv->data[rowIndex][j]);
    }
    free(csv->data[rowIndex]);

    // Shift  rows up by one
    for (int i = rowIndex; i < csv->row_count - 1; i++)
    {
        csv->data[i] = csv->data[i + 1];
    }

    csv->row_count--;
    free(splittedQuery);

    printf("Row deleted at index: %d\n", rowIndex);
}