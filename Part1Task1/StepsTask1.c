#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here

int count = 0;
char* dataRows[3];
char strFile[32];

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        
        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {

    FILE *dataFile = fopen("FitnessData_2023.csv","r");
    /*Count variable will be used later when finding the number of lines in a text file,
    create a string to display the data in the .csv file,
    and create a pointer to the file using the variable dataFile*/

    while (fgets(strFile, 32, dataFile)){
        count ++;
        /*Reads the data file and increments count every time a new line is detected,
         if a line is empty, the while loop breaks and count is the number of lines in the .csv file*/
    }

    printf("Number of records in file: %d\n", count);

    for (int i = 0; i <= 2; i++){
        fgets(strFile, 32, dataFile);
        //printf("%s", strFile);
        tokeniseRecord(strFile, ",", array[i][10], array[i][10], array[i][10]);
    }

    return 0;

}
