#include <commands.h>
#include <stdio.h>
#include <stdlib.h>

void add_row(CSVFile *csv)
{
    char *s;
    for (int j = 0; j < csv->col_count; j++)
    {
        printf("Provide value for the column : %s", csv->data[0][j]);
        scanf("%s", s);
    }
}