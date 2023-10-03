#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // for using INT_MIN INT_MAX in linux

#include "../Headers/Binary Tree.h"

int main(){
    int arrSize = 6;
    printf("no of nodes in the tree: ");
    scanf("%d", &arrSize);
    int inp[arrSize];
    printf("enter %d elements:\n", arrSize);
    for (int i = 0; i < arrSize; ++i)
        scanf("%d", &inp[i]);

    struct node* root = NULL;
    root = insertLevelOrder(root, inp, 0, arrSize);

    printf("inorder: ");
    inOrder(root);
    printf("\npreorder: ");
    preOrder(root);
    printf("\npostorder: ");
    postOrder(root);

    printf("height: %d\n", height(root));
    printf("node count: %d\n", nodeCount(root));
    printf("leaf node count: %d\n", countLeafNodes(root));
    printf("min node: %d\n", minNode(root));
    printf("min node: %d\n", maxNode(root));

    // mirror image, print leaf nodes, print nodes level wise.
    printf("leaf nodes are: ");
    printLeaf(root);
    printf("\n");

    // mirrors the tree
    mirrorTree(root);

    // levelwise print
    printLevelWise(root);
    printf("\n");

    return 0;
}