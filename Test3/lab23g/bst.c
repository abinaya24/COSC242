#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "mylib.h"

struct bst_node { /* should live in bst.c */
    char *key;
    bst left;
    bst right;
};

bst bst_free(bst b){

    if (b == NULL){
        return b;
    } else {
        bst_free(b->left);
        bst_free(b->right);
       
        free(b->key);
        free(b);
    }
    return b;
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

    if (b == NULL || b->key == NULL){

        if (b == NULL){
            b = bst_new();
        }
        b->key = emalloc(strlen(str) * sizeof str[0]+1);
        strcpy (b->key, str);
    } else if (strcmp(b->key, str) == 0){
        
    } else if (strcmp(b->key, str) < 0){
        b->right = bst_insert(b->right, str);
    } else {
        b->left = bst_insert(b->left, str);
    }
    return b;
}

bst bst_new(){

    bst result;

    result = emalloc (sizeof *result;)
    result->key = NULL;
    result->left = NULL;
    result->right = NULL;

    return result;
}

void bst_preorder(bst b, void f(char *str)){
    
    if (b == NULL){
        return;
    }
    f(b->key);
    bst_preorder(b->left, f);
    bst_preorder(b->right, f);
}

int bst_search(bst b, char *str){

    if (b == NULL){
        return 0;
    } else if (strcmp(b->key, str) == 0){
        return 1;
    } else if (strcmp(b->key, str) < 0){
        return bst_search(b->right, str);
    } else {
        return bst_search(b->left, str);
    }

    return 0;
        
}

