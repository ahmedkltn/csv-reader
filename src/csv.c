#include <csv.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

CSVFile *read_csv(const char *filename, const char sep)
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

    char buffer[3024];
    long nLine = 0;
    int maxRecords = 10;
    csvFile->data = (char ***)malloc(maxRecords * sizeof(char **)); // Initial allocation for 10 rows
    if (csvFile->data == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        free(csvFile);
        fclose(file);
        return NULL;
    }

    while (fgets(buffer, sizeof(buffer), file))
    {
        size_t len = strlen(buffer);
        // Remove existing newline if present
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }

        int count = 0;
        char **lineSplitted = split_line(buffer, sep, &count);
        if (nLine == 0)
        {
            csvFile->col_count = count;
        }
        // reallocate if number line > already allocated
        if (nLine >= maxRecords)
        {
            maxRecords *= 2;
            csvFile->data = (char ***)realloc(csvFile->data, maxRecords * sizeof(char **));
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
        for (int j = 0; j < csv->col_count - 1; j++)
        {
            free(csv->data[i][j]);
        }
    }
    free(csv);
}

void head_csv(const CSVFile *csv, const int from, const int to)
{
    // Return early if starting point exceeds available rows
    if (from > csv->row_count)
    {
        return;
    }

    int count = from;

    // Print header row if not starting from beginning
    if (from != 0)
    {
        for (int j = 0; j < csv->col_count - 1; j++)
        {
            printf("\t%s", csv->data[0][j]);
        }
        printf("\n");
    }

    // Print data rows
    for (int i = from; i < csv->row_count && count <= to; i++)
    {
        for (int j = 0; j < csv->col_count - 1; j++)
        {
            printf("\t%s", csv->data[i][j]);
        }
        printf("\n");
        count++;
    }
    printf("\n");
}

void write_csv(const char *filename, CSVFile *csv, const char sep)
{
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        return;
    }

    for (int i = 0; i < csv->row_count; i++)
    {
        char *s = join_line(csv->data[i], sep, csv->col_count - 1);
        fprintf(f, "%s\n", s);
        free(s);
    }

    fclose(f);
}