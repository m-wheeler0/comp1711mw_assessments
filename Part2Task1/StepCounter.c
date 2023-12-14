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
            if (strcmp(fileName, "") == 0){
                printf("Input filename.");
                continue;
            }
            dataFile = fopen(fileName, "r");
            perror("");
            fgets(strFile, 32, dataFile);
            printf("\n");
            
        }
        else if (selection == 'B'){
            rewind(dataFile);
            while (fgets(strFile, 32, dataFile)){
                recordCount++;
            }
            printf("Total records: %d\n\n", recordCount);

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
            printf("Fewest steps: %d\n\n", lowestStepCount);
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
            printf("%s\n", largestStepTime);
        }
        else if (selection == 'E'){
            rewind(dataFile);
            stepCount = 0;
            while (fgets(strFile, 32, dataFile)){
                tokeniseRecord(strFile, ",", fitnessData.date, fitnessData.time, fitnessData.steps);
                stepCount = stepCount + atoi(fitnessData.steps);
                recordCount++;
            }

            printf("%d\n\n", (stepCount/recordCount));
        }
        else if (selection == 'F'){
            char streakStart[32];
            char longestStreakStart[32];
            char streakEnd[32];
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
                        continue;
                    }
                    streakLength = 0;
                    
                }
            }
            printf("%s", longestStreakStart);
            printf("%s", streakEnd);
            printf("\n");
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