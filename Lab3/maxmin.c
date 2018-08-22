#include <stdio.h>
#include <stdlib.h>

void max_min(int *a, int n, int *max, int *min){

    int i;
    int prev = a[0];

    for(i=1; i<n; i++){
        if (a[i] > prev){
            *max = a[i];
            prev = a[i];
        }
    }
    prev = a[0];

    for(i=1; i<n; i++){
        if (a[i] < prev){
            *min = a[i];
            prev = a[i];
        }
    }
       
}

int main(void){

    int my_array[] = {5, 2, 7, 3, 4};
    int biggest, smallest;
    max_min(my_array, 5, &biggest, &smallest);
    printf("max value is %d, min value is %d\n", biggest, smallest);

    return EXIT_SUCCESS;
}
