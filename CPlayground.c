#include <stdio.h>

int main() {
    int array[5];

    for (int i = 0; i < 5; i++){
        array[i] = i * 10 + i;
    }
        
    printf("%d,%d,%d,%d,%d\n",array[0],array[1],array[2],array[3],array[4]);

    return 0;
}