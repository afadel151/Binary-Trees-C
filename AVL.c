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
 * two rotation functions
 * get balance factor of a node
 * AVL insertion - BST + update height + rotate if req
*/

int heightAVL(struct node* root){
    if(!root)
        return 0;
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

struct node* leftRotate(struct node* root){
    // set pointers
    struct node* x, *y;
    x = root->right;
    y = x->left;

    // rotate
    x->left = root;
    root->right = y;

    // update height
    root->height = height(root);
    x->height = height(x);
    // return new root
    return x;
}

int getBalance(struct node* root){
    if(root == NULL)
        return 0;
    // if(root->left == NULL && root->right != NULL)
    //     return root->right->height;
    // if(root->left != NULL && root->right == NULL)
    //     return root->left->height;
    // here functions are called instead of accessing height to struct
    // because function can handle null pointer
    return heightAVL(root->left) - heightAVL(root->right);
}

struct node* insertAVL(struct node* root, int key){
    // insertBST
    if(root == NULL)
        return createNode(key);
    else if(key < root->data)
        root->left = insertAVL(root->left, key);
    else if(key > root->data)
        root->right = insertAVL(root->right, key);
    else
        return root;

    // update height
    root->height = height(root);

    // check balance factor
    int bal = getBalance(root);

    // rotations if required
    // RR
    if(bal > 1 && root->left->data > key)
        return rightRotate(root);
    // LL
    if(bal < -1 && root->right->data < key)
        return leftRotate(root);
    // LR
    if(bal > 1 && root->left->data < key){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RL
    if(bal < -1 && root->right->data > key){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    // no rotations
    return root;
}

void main(){
    struct node* root = NULL;
    root = insertAVL(root, 30);
    root = insertAVL(root, 10);
    root = insertAVL(root, 20);
    root = insertAVL(root, 40);
    root = insertAVL(root, 50);
    printLevelWise(root);
    inOrder(root);
    printf("\n");

}
