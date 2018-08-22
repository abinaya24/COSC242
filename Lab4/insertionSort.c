#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/* Implementation of insertion sort.
   Takes the pointer for the beginning of the array and array length
   and sorts the array in place */
void insertion_sort(int *a, int n){

    int i, j;
    int key;

    /* Iterate through array, making each element the key */
    for(i=1; i<n; i++){
        key = a[i];
        j = i-1;
        /* Move all elements smaller than and to the left of
           the key one place to the right */
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        /* Insert the key (currently being sorted) into its place */
        a[j+1] = key;
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
    insertion_sort(my_array, count);
    end = clock();

    /* Print out the sorted contents of array, and the time it took. */
    for(i = 0; i < count; i++){
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
