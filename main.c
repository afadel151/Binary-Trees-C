#include <stdio.h>
#include <stdlib.h>

// height
// no of leafnodes
// min elem

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

int main(){
    int arrSize = 8;
//    printf("no of nodes in the tree: ");
//    scanf("%d", &arrSize);
    int inp[arrSize];
//    printf("enter %d elements:\n", arrSize);
    for (int i = 0; i < arrSize; ++i)
        inp[i] = i;
//        scanf("%d", &inp[i]);

    struct node* root = NULL;
    root = insertLevelOrder(root, inp, 0, arrSize);

//    printf("inorder: ");
//    inOrder(root);
//    printf("\npreorder: ");
//    preOrder(root);
//    printf("\npostorder: ");
//    postOrder(root);

    printf("height: %d", height(root));

}