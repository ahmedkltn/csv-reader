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

    // look for the end of file
    fseek(file, 0, SEEK_END);
    csvFile->row_count = ftell(file);
    // set the cursor back to 0
    fseek(file, 0, SEEK_SET);

    char buffer[1024];

    long nLine = 0;
    csvFile->data = (char ***)malloc(csvFile->row_count * sizeof(char **));
    while (fgets(buffer, sizeof(buffer), file))
    {
        // if the first time read the columns
        if (nLine == 0)
        {
            csvFile->col_count = (long)strlen(buffer);
        }
        char del = ';';
        int count = 0;
        char **lineSplitted = split_line(buffer, del, &count);
        csvFile->data[nLine] = lineSplitted;
        nLine++;
    }

    fclose(file);
    return csvFile;
}