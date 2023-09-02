#include <stdio.h>
#include <stdlib.h>
// #include "Headers/Binary Tree.h"

typedef struct RBTnode node;

/*
 * in RBT every node has either red or black color
 * NULL is considered as black
 * in RBT two methods are used for balencing
 * 1. Recoloring
 * 2. Rotation
 *
 * Algorithm
 * 1. insert BST
 * 2. if(x == root) setColour(black)
 * 3. if(x->parent == black) exit
 * 4. if(x != root || x->parent->color == red)
 * 		1. if (x->uncle == red)
 * 			1.setColor of parent and uncle as black
 * 			2. color grandparent red
 * 		2. if (x->uncle == black)
 * 			1. suitable rotation
 */

struct RBTnode{
    int data;
    short int color;  // 0 - black, 1 - red
    struct RBTnode* left;
    struct RBTnode* right;
    struct RBTnode* parent;
};

void main(){
    return;
}
