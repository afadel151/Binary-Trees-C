#include <stdio.h>
#include "Headers/Binary Tree.h"

// to be done
// create bst
// bst insertion
// bst deletion 3 cases

struct node* insertBST(struct node* root, int data){
    if(root == NULL){
        root = createTree(data);
        return root;
    }
    struct node* rootCpy = root;
    struct node* newNode = createNode(data);
    while(1){
        if(data < root->data){
            if(root->left == NULL){
                root->left = newNode;
                return rootCpy;
            }
            else 
                root = root->left;
        }
        else if(data > root->data){
            if(root->right == NULL){
                root->right = newNode;
                return rootCpy;
            }
            else 
                root = root->right;
        }
    }
    return rootCpy;
}

struct node* createBST(int* arr, int count){
    struct node* root = NULL;
    for(int i = 0; i < count; i++)
        root = insertBST(root, arr[i]);
    return root;
}

void main(){
    int arr[] = {4,2,1,3,6,5,7};
    int size = sizeof(arr)/sizeof(int);

    struct node* root = createBST(arr, size);
    
    printLevelWise(root);
}