#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"

struct flexarrayrec{
    int capacity;
    int itemcount;
    int *items;
};

flexarray flexarray_new(){
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

void flexarray_append(flexarray f, int num){
    if (f->itemcount == f->capacity){
        f->capacity += f->capacity;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount++] = num;
}

void flexarray_print(flexarray f){
    int i;

    for (i = 0; i < f->itemcount; i++){
        printf("%d\n", f->items[i]);
    }
}

static void merge(int *a, int *w, int n){

    int i = 0, j = n/2, count = 0;

    while (i < n/2 && j < n){
        if (a[i] <= a[j]){
            w[count] = a[i];
            i++;
        } else {
            w[count] = a[j];
            j++;
        }
        count++;
    }
    if(i >= n/2){
        while (j < n){
            w[count] = a[j];
            j++;
            count++;
        }
    }
    if(j >= n){
        while (i < n/2){
            w[count] = a[i];
            i++;
            count++;
        }
    }
}

static void merge_sort(int *a, int *w, int n){

    int i;

    if (n < 2){
        return;
    } else {
        merge_sort(a, w, n/2);
        merge_sort(a + (n/2), w, n - (n/2));

        merge(a, w, n);

        for (i=0; i < n; i++){
            a[i] = w[i];
        }

        return;
    }
}

void flexarray_sort(flexarray f){

    int *workspace = emalloc(f->itemcount * sizeof f->items[0]);
    merge_sort(f->items, workspace, f->itemcount);
    free(workspace);
}

void flexarray_free(flexarray f){

    free(f->items);
    free(f);
}


