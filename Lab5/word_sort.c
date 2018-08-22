#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define STRING_LEN 80
#define ARRAY_LEN 10000

/* Implementation of selection sort.
   Takes the pointer for the beginning of the array and array length
   and sorts the array in place */
void selection_sort(char **a, int n){

    int i, j;
    int min;
    char *temp;

    for(i=0; i<n; i++){

        min = i;
        /* Finding the smallest element to the right of element
           currently being sorted */
        for(j=i+1; j<n; j++){
            if (strcasecmp(a[j], a[min]) < 0){
                min = j;
            }
        }
        /* Swapping element currently being sorted and the smallest element */
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }    
}


void *emalloc(size_t s){
    void *result = malloc(s);
    if (NULL == result){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

int main(void){

    char word[STRING_LEN];
    char *wordlist[ARRAY_LEN];
    int num_words;
    int i;

    num_words = 0;
    while (num_words < ARRAY_LEN && 1 == scanf("%79s", word)){
        wordlist[num_words] = emalloc((strlen(word) + 1) * sizeof wordlist[0][0]);
        strcpy(wordlist[num_words], word);
        num_words++;
    }

    selection_sort(wordlist, num_words);

    for(i=0; i < num_words; i++){
        printf("%s\n", wordlist[i]);
    }

    for (i=0; i < num_words; i++){
        free(wordlist[i]);
    }

    return EXIT_SUCCESS;
}
    
