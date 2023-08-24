#include <stdio.h>
#include <stdlib.h>
#include "Headers/Binary Tree.h"

// AVL trees is a BST with hight diff of left and right subtree not more than one
// thus AVL is self balenced
//
// operations on BST are O(h) thus optimizing height is must
//
// types of rotation
// 1. left
// 2. right
//
// 4 cases of rotation
// LL
// LR
// RL
// RR

/*
 * To-Do
 * height - get height of subtree from struct
 * 4 rotation functions
 * get balance factor of a node
 * AVL insertion - BST + update height + rotate if req
*/

int heightAVL(struct node* root){
    if(!root)
        return -1;
    return root->height;
}

struct node* rightRotate(struct node* root){
    // set pointers
    struct node* x, *y;
    x = root->left;
    y = x->right;

    // rotate
    x->right = root;
    root->left = y;

    // update height
    root->height = height(root);
    x->height = height(x);

    // return new root
    return x;
}


void main(){
    printf("%d\n", heightAVL(NULL));
}
