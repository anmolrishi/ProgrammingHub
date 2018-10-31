#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    int *array;
    int tam;
    printf("How many elements from the Fibonacci sequence do you want to calculate?: ");
    scanf("%d", &tam);
    //dynamic memory allocation
    array = (int *)malloc(tam*sizeof(int));
    //basecases from fibonacci sequence
    array[0] = 1;
    array[1] = 1;
    for(int i = 2; i <= tam-1; i++){
        array[i] = array[i-1] + array[i-2];
    }
    //printing the fibonacci sequence
    printf("Your fibonacci sequence is:\n");
    for(int i = 0; i < tam; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
