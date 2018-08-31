#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "mylib.h"

void print_key(char *s)
{
    printf("%s\n",s);
}

int main(void){
    bst b;
    char word[256];
    char op;

    b = bst_new();

    while (2 == scanf(" %c %255s", &op, word)) {
        if ('+' == op) {
            b = bst_insert(b, word);
        } else if ('?' == op) {
            /*printf("%d\n", bst_search(b, word));*/
        }
    }

    bst_inorder(b, print_key);

    bst_delete(b, "sociable");

    printf("\n\nDeleted\n");

    bst_inorder(b, print_key);
    
   
    b = bst_free(b);

    return EXIT_SUCCESS;
}
