#include "FitnessDataStruct.h"

char selection, fileName[32], strFile[32];
int recordCount, stepCount, stepTotal;
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
            printf("Input filename: ");
            scanf("%s", fileName);
            dataFile = fopen(fileName, "r");
            if (dataFile == NULL){
                return 1;
            }
            else{
                fgets(strFile, 32, dataFile);
            }
            printf("\n");
            
        }
        else if (selection == 'B'){
            rewind(dataFile);
            while (fgets(strFile, 32, dataFile)){
                recordCount++;
            }
            printf("Total records: %d\n", recordCount);

            recordCount = 0;
        }
        else if (selection == 'C'){
            int lowestStepCount = 20000;
            rewind(dataFile);
            while (fgets(strFile, 32, dataFile)){
                tokeniseRecord(strFile, ",", fitnessData.date, fitnessData.time, fitnessData.steps);
                stepCount = atoi(fitnessData.steps);
                if (stepCount < lowestStepCount){
                    lowestStepCount = stepCount;
                }

            }
            printf("Fewest steps: %d\n", lowestStepCount);
        }
        else if (selection == 'D'){
            int largestStepCount = 0;
            char largestStepTime[32];
            rewind(dataFile);
            while (fgets(strFile, 32, dataFile)){
                tokeniseRecord(strFile, ",", fitnessData.date, fitnessData.time, fitnessData.steps);
                stepCount = atoi(fitnessData.steps);
                if (stepCount > largestStepCount){
                    largestStepCount = stepCount;
                    sprintf(largestStepTime ,"Largest steps: %s %s\n", fitnessData.date, fitnessData.time);
                }
            }
            printf("%s", largestStepTime);
        }
        else if (selection == 'E'){
            rewind(dataFile);
            stepCount = 0;
            while (fgets(strFile, 32, dataFile)){
                tokeniseRecord(strFile, ",", fitnessData.date, fitnessData.time, fitnessData.steps);
                stepCount = stepCount + atoi(fitnessData.steps);
                recordCount++;
            }

            printf("Mean step count: %d\n", (stepCount/recordCount));
        }
        else if (selection == 'F'){
            char streakStart[50];
            char longestStreakStart[50];
            char streakEnd[50];
            int streakLength = 0;
            int bestStreak = 0;
            int currentStreak = 0;

            rewind(dataFile);

            while(fgets(strFile, 32, dataFile)){
                tokeniseRecord(strFile, ",", fitnessData.date, fitnessData.time, fitnessData.steps);
                if (atoi(fitnessData.steps) > 500 && streakLength == 0){
                    sprintf(streakStart, "Longest period start: %s %s\n", fitnessData.date, fitnessData.time);
                    streakLength ++;
                }
                else if(atoi(fitnessData.steps) > 500 && streakLength > 0){
                    streakLength ++;
                }
                else{
                    if (streakLength > bestStreak){
                        bestStreak = streakLength;
                        strcpy(longestStreakStart, streakStart);
                        sprintf(streakEnd, "Longest period end: %s %s\n", fitnessData.date, fitnessData.time);
                    } 
                    else{
                    }
                    streakLength = 0;
                }
            }
            printf("%s", longestStreakStart);
            printf("%s", streakEnd);
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