#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

FitnessData row;

int main() {
    char fileName[20];
    char outputName[24];
    char record[32];
    int highestCount = 9999, currentHighest = 0, stepCount;
    FILE *inputFile, *outputFile;

    while (fopen(fileName, "r") == NULL){
        printf("Enter your filename: ");
        scanf("%s", fileName);
        inputFile = fopen(fileName, "r");
    }

    sprintf(outputName, "%s.tsv", fileName);
    outputFile = fopen(outputName ,"a");

    while(fgets(record, 32, inputFile)){
        tokeniseRecord(record, ',', row.date, row.time, &row.steps);
        fprintf(outputFile, "Hello world\n");
        stepCount = row.steps;
        if (stepCount > currentHighest && stepCount < highestCount){
            currentHighest = stepCount;
        }
    }

    printf("Highest count: %d", currentHighest);

    fclose(inputFile);
    fclose(outputFile);
}
