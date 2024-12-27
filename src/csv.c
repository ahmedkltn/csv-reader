#include <csv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

CSVFile *read_csv(const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error while reading file %s\n", filename);
        return NULL;
    }

    CSVFile *csvFile = (CSVFile *)malloc(sizeof(CSVFile));
    if (csvFile == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        fclose(file);
        return NULL;
    }

    csvFile->row_count = 0;
    csvFile->col_count = 0;

    char buffer[1024];
    long nLine = 0;
    csvFile->data = (char ***)malloc(10 * sizeof(char **)); // Initial allocation for 10 rows
    if (csvFile->data == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        free(csvFile);
        fclose(file);
        return NULL;
    }

    while (fgets(buffer, sizeof(buffer), file))
    {
        int count = 0;
        char **lineSplitted = split_line(buffer, ';', &count);
        if (nLine == 0)
        {
            csvFile->col_count = count;
        }

        csvFile->data[nLine] = lineSplitted;
        nLine++;
    }

    csvFile->row_count = nLine;

    fclose(file);
    return csvFile;
}

void free_csv(CSVFile *csv)
{
    for (int i = 0; i < csv->row_count; i++)
    {
        for (int j = 0; j < csv->col_count; j++)
        {
            free(csv->data[i][j]);
        }
    }
    free(csv);
}

void head_csv(const CSVFile *csv, const int lines)
{
    printf("\n");
    int count = 0;
    for (int i = 0; i < csv->row_count; i++)
    {
        for (int j = 0; j < csv->col_count - 1; j++)
        {
            printf("\t%s", csv->data[i][j]);
        }

        printf("\n");
        if (count > lines)
        {
            break;
        }
        count++;
    }
    printf("\n");
}