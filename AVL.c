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

void main(){
    printf("%d\n", heightAVL(NULL));
}
