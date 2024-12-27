#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"
#include "commands.h"

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
        switch (action)
        {
        case 'B':
            printf("Thanks for using csv manager !");
            stop = 1;
            break;
        case 'A':
            add_row(csv);
            break;
        default:
            printf("Incorrect command inserted \n");
            break;
        }
    }

    free_csv(csv);

    return 0;
}