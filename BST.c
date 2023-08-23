#include <stdio.h>
#include "Headers/Binary Tree.h"


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
    if(root->left == NULL)
        return root;
    struct node* succ, *succParent;
    succ = root->left;
    while(succ->left != NULL){
        succ = succ->left;
    }
    return succ;
}

struct node* deleteBST(struct node* root, int key){
    if(root == NULL)
        return root;
    else if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(key < root->data)
        root->left = deleteBST(root->left, key);
    else if(key > root->data)
        root->right = deleteBST(root->right, key);
    else{
        struct node* succ = inorderSucc(root->right);
        root->data = succ->data;
        root->right = deleteBST(root->right, succ->data);
    }
    return root;
}

void main(){
    int arr[] = {4,2,1,3,6,5,7};
    int size = sizeof(arr)/sizeof(int);

    struct node* root = createBST(arr, size);
    
    printLevelWise(root);
    root = deleteBST(root, arr[5]);
    printLevelWise(root);

}