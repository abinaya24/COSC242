#include <stdlib.h>
#include <string.h>
#include "myib.h"
#include "bst.h"

struct bst_node {
    char *key;
    bst left;
    bst right;
};

bst bst_delete(bst b, char *str){
}

bst bst_free(best b){
}

void bst_inorder(bst b, void f(char *str)){

    if (b == NULL){
        return;
    }
    bst_inorder(b->left, f);
    f(b->key);
    bst_inorder(b->right, f);
}

bst bst_insert(bst b, char *str){

    if (b == NULL){
        
        b = emalloc(sizeof *b);
        b->key = emalloc(strlen(str) * size of str[0] + 1);
        strcpy(b->key, str);
    }
    else if (strcmp(b->key, str) == 0){
    }
    else if (strcmp(str, b->key) > 0){
        bst->right = bst_insert(bst->right, str);
    }
    else{
        bst->left = bst_insert(bst->left, str);
    }

    return b;
}

bst bst_new(){

    
}

void bst_preorder(bst b, void f(char *str)){

    if (b == NULL){
        return;
    }
    f(b->key);
    bst_preorder(bst->left, f);
    bst_preorder(bst->right, f);
}

int bst_search(bst b, char *str){

    if (b == NULL){
        return 0;
    }
    else if (strcmp(str, b->key) == 0){
        return 1;
    }
    else if (strcmp(str, b->key) > 0){
        return bst_search(b->right, str);
    }
    else{
        return bst_search(b->left, str);
    }
}
        
}
