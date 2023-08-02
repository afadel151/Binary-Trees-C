#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* createTree(int data){
    struct node* root = createNode(data);
    return root;
}

struct node* insertLevelOrder(struct node* root, int* arr, int index, int arrSize){
    if (index < arrSize) {
        struct node *temp = createNode(arr[index]);
        root = temp;

        root->left = insertLevelOrder(root->left, arr, 2*index+1, arrSize);
        root->right = insertLevelOrder(root->right, arr, 2*index+2, arrSize);
    }
    return root;
}

void inOrder(struct node* root){
    if(root->left != NULL)
        inOrder(root->left);
    printf("%d ", root->data);
    if(root->right != NULL)
        inOrder(root->right);
}

void preOrder(struct node* root){
    printf("%d ", root->data);
    if(root->left != NULL)
        preOrder(root->left);
    if(root->right != NULL)
        preOrder(root->right);
}

void postOrder(struct node* root){
    if(root->left != NULL)
        postOrder(root->left);
    if(root->right != NULL)
        postOrder(root->right);
    printf("%d ", root->data);
}

int height(struct node* root){
    if( root == NULL)
        return 0;
    else{
        int lh = height(root->left)+1;
        int rh = height(root->right)+1;
        return (lh > rh ? lh : rh);
    }
}

int nodeCount(struct node* root){
    if( root == NULL)
        return 0;
    else{
        int count = nodeCount(root->left);
        count += nodeCount(root->right);
        return count+1;
    }
}

int countLeafNodes(struct node* root){
    if( root == NULL )
        return 0;
    if( root->left == NULL && root->right == NULL)
        return 1;
    int count = countLeafNodes(root->left);
    count += countLeafNodes(root->right);
    return count;
}

int minNode(struct node* root){
    if( root == NULL )
        return INT_MAX;
    int curr = root->data;
    int lres = minNode(root->left);
    int rres = minNode(root->right);

    if( lres < curr)
        curr = lres;
    else if ( rres < curr )
        curr = rres;
    return curr;
}

int maxNode(struct node* root){
    if( root == NULL)
        return INT_MIN;
    int curr = root->data;
    int lres = maxNode(root->left);
    int rres = maxNode(root->right);

    if(lres>curr)
        curr = lres;
    else if (rres > curr)
        curr = rres;
    return curr;
}

void printLeaf(struct node* root){
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL){
        printf("%d ", root->data);
        return;
    }
    printLeaf(root->left);
    printLeaf(root->right);
}

void mirrorTree(struct node* root){
    if (root == NULL)
        return;
    mirrorTree(root->left);
    mirrorTree(root->right);
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void printNthLevel(struct node* root, int level){
    if (root == NULL)
        return;
    if ( level == 1 )
        printf("%d ", root->data);
    else{
        printNthLevel(root->left, level-1);
        printNthLevel(root->right, level-1);
    }
}

void printLevelWise(struct node* root){
    int h = height(root);
    printf("Levelwise print:\n");
    for(int i = 1; i <= h; i++){
        printNthLevel(root, i);
        printf("\n");
    }
}