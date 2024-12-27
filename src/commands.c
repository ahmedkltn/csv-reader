#include <commands.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_row(CSVFile *csv)
{
    char *s = NULL;
    size_t buffsize;

    // reallocate memory for new row
    csv->data = realloc(csv->data, csv->row_count * sizeof(char **));
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