#include "FitnessDataStruct.h"

char selection, fileName[32], strFile[32];
int recordCount, stepCount;
FILE *dataFile;
FITNESS_DATA fitnessData;

int main() {

    while (selection != 'Q'){
        printf("What option would you like to choose?\n"
        "A. Specify the filename to be imported\n"
        "B. Display the total number of records on the file\n"
        "C. Find the date and time with the fewest steps\n"
        "D. Find the data and time with the most steps\n"
        "E. Find the mean step count of all recorded data in the file\n"
        "F. Find the longest continuous streak of having over 500 steps per record\n"
        "Q. Quit\n");
        scanf(" %c", &selection);

        if (selection == 'A'){
            printf("Enter the filename: ");
            scanf("%s", fileName);
            if (fileName == ""){
                printf("Please input a filename.");
                continue;
            }
            dataFile = fopen(fileName, "r");
            perror("");
            tokeniseRecord(strFile, ",", fitnessData.date, fitnessData.time, fitnessData.steps);
            printf("\n");
            
        }
        else if (selection == 'B'){
            rewind(dataFile);
            while (fgets(strFile, 32, dataFile)){
                recordCount++;
            }
            printf("The number of records in this data file is: %d\n\n", recordCount);
            recordCount = 0;
        }
        else if (selection == 'C'){
            int lowestStepCount = 20000;
            rewind(dataFile);
            while (fgets(strFile, 32, dataFile)){
                stepCount = atoi(fitnessData.steps);
                printf("%s", strFile);
                printf("%s", fitnessData.date);
                if (stepCount < lowestStepCount && stepCount != 0){
                    lowestStepCount = stepCount;
                }

            }
            printf("Fewest steps:%d\n", lowestStepCount);
            perror("");
            printf("\n\n");
        }
        else if (selection == 'D'){
            perror("");
        }
        else if (selection == 'E'){
            perror("");
        }
        else if (selection == 'F'){
            perror("");
        }
        else if (selection == 'Q'){
            fclose(dataFile);
            exit(0);
        }
        else{
            printf("Invalid answer\n");
        }
    }
    return 0;
}