#include <stdio.h>
#include "Headers/Binary Tree.h"

// to be done
// bst deletion 3 cases
/*
    NO CHILD: set ancesotrs to point NULL 
                and free node
    SINGLE CHILD: set ancestor->next = child
                and free node
    TWO CHILD: inorder predecessor or inorder successor
*/ 

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

struct node* searchBST(struct node* root, int key){
    if(root == NULL)
        return root;
    while (root != NULL){
        if(key < root->data)
            root = root->left;
        else if(key > root->data)
            root = root->right;
        else if(key == root->data)
            return root;
    }
    printf("Node not found\n");
    return root;
}

struct node* inorderSucc(struct node* root){
    // finding the leftmost child of the right subtree
    // do not use for a tree with only one element
    if(root->left == NULL)
        return NULL;
    struct node* succ, *succParent;
    succ = root->left;
    succParent = root;
    while(succ->left != NULL){
        succParent = succParent->left;
        succ = succ->left;
    }
    // printf("succParent: %d\nsucc: %d", succParent->data, succ->data);
    return succ;
}


void main(){
    int arr[] = {4,2,1,3,6,5,7};
    int size = sizeof(arr)/sizeof(int);

    struct node* root = createBST(arr, size);
    
    printLevelWise(root);

    struct node* thrash = inorderSucc(root);
    struct node* res = searchBST(root, arr[0]);
    if( res->data == arr[0])
        printf("pass\n");
}