#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mylib.h"
#include "bst.h"

struct bst_node {
    char *key;
    bst left;
    bst right;
};



bst bst_delete(bst b, char *str){

    bst temp;
    
    if (b == NULL){
        return b;
    }
    else if (strcmp(b->key, str) == 0){
        if (b->left == NULL && b->right == NULL){
            free(b->key);
            free(b);
            return NULL;
        }
        else if(b->left != NULL && b->right == NULL){
            free(b->key);
            free(b);
            return b->left;
        }
        else if(b->right != NULL && b->left == NULL){
            free(b->key);
            free(b);
            return b->right;
        }
        else{
            temp = b->right;
            while (temp->left != NULL){
                temp = temp->left;
            }
            strcpy(b->key, temp->key);
            b->right = bst_delete(b->right, temp->key);
            return b;
        }

    }
    else if(b->left != NULL && strcmp(b->key, str) > 0){
        b->left = bst_delete(b->left, str);
    }

    else if(b->right != NULL && strcmp(b->key, str) < 0){
        b->right = bst_delete(b->right, str);
    }

    return b;


}

bst bst_free(bst b){

    if (b == NULL){
        return b;
    }else{
        bst_free(b->left);
        bst_free(b->right);
        free(b->key);
        free(b);
        return b;
    }
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
        b->key = emalloc(strlen(str) * sizeof str[0] + 1);
        strcpy(b->key, str);
    }
    else if (strcmp(b->key, str) == 0){
    }
    else if (strcmp(str, b->key) > 0){
        b->right = bst_insert(b->right, str);
    }
    else{
        b->left = bst_insert(b->left, str);
    }

    return b;
}

bst bst_new(){

    return NULL;
    
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
