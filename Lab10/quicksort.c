#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX 10000

void quick_sort(int *a, int n){

    int pivot, i, j, temp;
    
    if (n < 2){
        return;
    }

    pivot = a[0];;

    for(i = -1, j = n;;){
        do {
            i++;
        } while (a[i] < pivot);
        do {
            j--;
        } while (a[j] > pivot);
        if (i < j){
            printf("Swapping %d and %d\n", a[i], a[j]);
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            break;
        }
    }

    quick_sort(a, j+1);
    quick_sort(a+j+1, n-j-1);
}


int main(void){

    int i, num_items = 0;
    int num_list[ARRAY_MAX];

    while(num_items < ARRAY_MAX && 1 == scanf("%d", &num_list[num_items])){
        num_items++;
    }

    printf("Length: %d\n", num_items);
    quick_sort(num_list, num_items);

    for(i = 0; i < num_items; i++){
        printf("%d\n", num_list[i]);
               
    }
    return EXIT_SUCCESS;
    
}



