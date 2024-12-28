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
    int from = 0;
    int to = 10;
    char toSearch[200], toDelete[200];
    char action;
    while (!stop)
    {
        // read from 0 to 10
        head_csv(csv, from, to);

        printf("[L] Look [S] Search [A] Add [D] Delete [B] Break ");
        scanf(" %c", &action);
        switch (action)
        {

        case 'L':
            printf("From Line : ");
            scanf("%d", &from);
            printf("To Line : ");
            scanf("%d", &to);
            break;
        case 'B':
            printf("Thanks for using csv manager !");
            stop = 1;
            break;
        case 'S':
            printf("Enter query where Column=Condition : ");
            scanf(" %s", toSearch);
            search_csv(csv, toSearch);
            break;
        case 'D':
            printf("Enter query where Column=Condition : ");
            scanf(" %s", toDelete);
            delete_row(csv, toDelete);
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