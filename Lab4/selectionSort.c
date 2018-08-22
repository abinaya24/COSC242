#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/* Implementation of selection sort.
 Takes the pointer for the beginning of the array and array length
 and sorts the array in place */
void selection_sort(int *a, int n){

    int i, j;
    int min, temp;

    for(i=0; i<n; i++){

        min = i;
        /* Finding the smallest element to the right of element
           currently being sorted */
        for(j=i+1; j<n; j++){
            if (a[j] < a[min]){
                min = j;
            }
        }
        /* Swapping element currently being sorted and the smallest element */
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }    
}

int main(void){

    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;

    /* Put items into array and keep track of how many elements. */
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])){
        count ++;
    }

    /* Start clock, run sorting function, stop clock. */
    start = clock();
    selection_sort(my_array, count);
    end = clock();

    /* Print out the sorted contents of array, and the time it took. */
    for(i = 0; i < count; i++){
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
