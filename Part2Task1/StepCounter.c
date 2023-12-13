#include "FitnessDataStruct.h"

int count = 0;
char strFile[32];
char fileName[32];
char selection;
FILE *dataFile;

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
        scanf("%c", &selection);

        if (selection == 'A'){
            printf("Enter the filename: ");
            scanf("%s", fileName);
            fopen(fileName, "r");
            perror("Error");
        }
        else if (selection == 'B'){
            printf("B\n");
        }
        else if (selection == 'C'){
            printf("C\n");
        }
        else if (selection == 'D'){
            printf("D\n");
        }
        else if (selection == 'E'){
            printf("E\n");
        }
        else if (selection == 'F'){
            printf("F\n");
        }
        else if (selection == 'Q'){
            exit(0);
        }
        else{
            printf("Invalid answer\n");
        }
    }
    return 0;
}