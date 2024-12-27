#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"
#include "utils.h"

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

    int stop = 0;
    char action;
    while (!stop)
    {
        head_csv(csv, 10);

        printf("[S] Search [A] Add [D] Delete [B] Break ");
        scanf(" %c", &action);
        if (action != 'S' && action != 'A' && action != 'D' && action != 'B')
        {
            printf("Incorrect command inserted \n");
        }
        if (action == 'B')
        {
            break;
        }
    }

    free(csv);

    return 0;
}