#include <stdio.h>
#include <stdlib.h>

#define OCEAN_MAX 41981

struct ocean_datum{
    int x;
    int y;
    double conc;
};

/* Compares oxygen levels. Returns 1 if a>b, 0 if a=b, -1 if a<b */
int cmp_ocean_struct(struct ocean_datum *a, struct ocean_datum *b){

    if((*a).conc > (*b).conc){
        return 1;
    } else if ((*a).conc == (*b).conc){
        return 0;
    } else{
        return -1;
    }
}

/* Implementation of selection sort.
   Takes the pointer for the beginning of the array and array length
   and sorts the array in place */
void selection_sort(struct ocean_datum *o, int n){

    int i, j;
    int min;
    struct ocean_datum temp;

    for(i=0; i<n; i++){

        min = i;
        /* Finding the smallest element to the right of element
           currently being sorted */
        for(j=i+1; j<n; j++){
            if (cmp_ocean_struct(&o[j], &o[min]) < 0){
                min = j;
            }
        }
        /* Swapping element currently being sorted and the smallest element */
        temp = o[i];
        o[i] = o[min];
        o[min] = temp;
    }    
}

void print_ocean_datum(struct ocean_datum *o){
    printf("%d %d %.4f\n", (*o).x, (*o).y, (*o).conc);
}

int read_ocean_datum(struct ocean_datum *o){
    return 3 == scanf("%d %d %lg", &(*o).x, &(*o).y, &(*o).conc);
}

int main(void){
    struct ocean_datum ocean_data[OCEAN_MAX];
    int num_items;
    int i;

    num_items = 0;
    while (num_items < OCEAN_MAX && read_ocean_datum(&ocean_data[num_items])){
        num_items++;
    }

    /* sort data here */
    selection_sort(ocean_data, num_items);

    /* print out the array of structs */
    for(i = 0;i < num_items; i++){
        print_ocean_datum(&ocean_data[i]);
    }

    return EXIT_SUCCESS;
}
