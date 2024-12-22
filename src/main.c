#include <stdio.h>
#include <string.h>
#include "csv.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    CSVFile *csv = read_csv(argv[1]);
    if (!csv)
    {
        printf("Failed to read CSV file.\n");
        return 1;
    }
    for (int i = 0; i < csv->row_count; i++)
    {
        size_t s = strlen(csv->data[i]);
        for (int j = 0; j < s; j++)
        {
            printf("\t%s\t|", csv->data[i][j]);
        }
        printf("\n");
    }

    // // Print CSV data (to be implemented)
    // free_csv(csv);
    return 0;
}