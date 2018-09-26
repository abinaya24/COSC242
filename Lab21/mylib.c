/**
 * File: mylib.c
 * @author: Josh King.
 */

#include <stdio.h>
#include <stdlib.h> 
#include "mylib.h"

/**
 * Function: emalloc
 * Purpose: allocates a block of memory.
 *
 * @param s the size (bytes) of memory required for allocation.
 * @return the memory address where it has been allocated.
 */
void *emalloc(size_t s){
    void *result = malloc(s);
    if(NULL == result){
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

/**
 * Function: erealloc
 * Purpose: reallocates a block of memory.
 *
 * @param p is a void pointer to reallocate memory.
 * @param s the size (bytes) of memory required for reallocation.
 * @return the memory address where it has been reallocated.
 */
void *erealloc(void *p, size_t s){
    void *result = realloc(p, s);
    if (NULL == result){
        fprintf(stderr, "Memory reallocation failed.\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
