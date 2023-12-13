#include "FitnessDataStruct.h"

char selection, fileName[32], strFile[32];
int recordCount;
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
            dataFile = fopen(fileName, "r");
            perror("");
            tokeniseRecord(strFile, ",", fitnessData.date, fitnessData.time, fitnessData.steps);
            printf("\n\n");
            
        }
        else if (selection == 'B'){
            while (fgets(strFile, 32, dataFile)){
                recordCount++;
            }
            printf("The number of records in this data file is: %d\n\n", recordCount);
        }
        else if (selection == 'C'){
            printf("Fewest steps: \n\n")
            perror("");
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