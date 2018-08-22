#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 30000

int binary_search(int *a, int n, int t){

    int m;
    
    if (n <= 0){
        return 0;
    }

    m = a[n/2];
    
    if (m == t){
        return 1;
    } else if (m > t){
        binary_search(a, n/2, t);
    } else {
        binary_search(&a[n/2], n/2, t);
    }

}

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

int main(int argc, char **argv){

    FILE *infile;
    int my_array[ARRAY_MAX];
    int num_items = argc;
    int target;

    if (NULL == (infile = fopen(argv[1], "r"))){
        fprintf(stderr, "%s: can't find file %s\n", argv[0], argv[1]);
        return EXIT_FAILURE;
        }

    num_items = 0;
    while (num_items < ARRAY_MAX &&
           1 == fscanf(infile, "%d", &my_array[num_items])){
        num_items++;
    }

    selection_sort(my_array, num_items);
    
    while (1 == scanf("%d", &target)){
        if (binary_search(my_array, num_items, target) == 1){
            printf("+\n");
        } else{
            printf("-\n");
        }
    }

    fclose(infile);

    return EXIT_SUCCESS;
}

    
