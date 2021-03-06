#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "htable.h"

struct htablerec{
    int capacity;
    int num_keys;
    char **keys;
};

htable htable_new(int cap){
    int i;
    htable result = emalloc(sizeof *result);
    result->capacity = cap;
    result->num_keys = 0;
    result->keys =
      emalloc(result->capacity * sizeof result->keys[0]);
    for (i = 0; i < result->capacity; i++){
        result->keys[i] = NULL;
        }
    return result;
}

void htable_free(htable h){
    int i;

    for (i = 0; i < h->capacity; i++){
        free(h->keys[i]);
    }
    free(h->keys);
    free(h);
}

static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
    while (*word != '\0') {
        result = ((*word++) + 31 * result);
    }
    return result;
}

int htable_insert(htable h, char *str){

    unsigned int hash = htable_word_to_int(str) % h->capacity;
    int count;

    if (!h->keys[hash]){
        h->keys[hash] = malloc(strlen(str) +1  * sizeof(h->keys[hash][0]));
        strcpy(h->keys[hash], str);
        h->num_keys++;

        return 1;
        
    } else if (strcmp(h->keys[hash], str) == 0){

        return 1;
        
    } else{
        count = 0;
        while(count <= h->capacity){
            hash++;
            hash = (hash)%h->capacity;
            
            if (h->keys[hash] == NULL){
                h->keys[hash] =
                    malloc(strlen(str) +1  * sizeof(h->keys[hash][0]));
                strcpy(h->keys[hash], str);
                h->num_keys++;

                return 1;
        
            } else if (strcmp(h->keys[hash], str) == 0){
                return 1;
                
            } else{
                count++;
            }
        }
        return 0;
    }
    

    
}

void htable_print(htable h, FILE *stream){

    int i;

    for (i = 0; i < h->capacity; i++) {
        fprintf(stream, "%2d %s\n", i, h->keys[i] == NULL ? "" : h->keys[i]);
    }
}
