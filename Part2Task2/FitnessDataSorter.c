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
    char highestTime[6];
    char highestDate[10];
    int highestCount = 9999, currentHighest, stepCount, recordCount;
    FILE *inputFile, *outputFile;

    while (fopen(fileName, "r") == NULL){
        printf("Enter your filename: ");
        scanf("%s", fileName);
        inputFile = fopen(fileName, "r");
    }

    sprintf(outputName, "%s.tsv", fileName);
    outputFile = fopen(outputName ,"a");

    while(fgets(record, 32, inputFile)){
        recordCount++;
    }

    rewind(inputFile);

    for(int i = 0; i < recordCount; i++){
        currentHighest = 0;
        while(fgets(record, 32, inputFile)){
            tokeniseRecord(record, ',', row.date, row.time, &row.steps);
            if (row.steps > currentHighest && row.steps < highestCount){
                printf("%d\n",row.steps);
                printf("%d\n",highestCount);
                currentHighest = row.steps;
                strcpy(highestTime, row.time);
                strcpy(highestDate, row.date);
            }
            else
            {
                currentHighest = currentHighest;
            }
        }
        highestCount = currentHighest; 
        fprintf(outputFile, "%s\t%s\t%d\n", highestDate, highestTime, currentHighest);
        printf("%d\n", highestCount);
        //Rushed due to deadlines, could not finish this sorting function
    }

    recordCount = 0;

    fclose(inputFile);
    fclose(outputFile);

    exit(0);
}
