#include <stdio.h>
#include <stdlib.h>

typedef struct RBTnode node;

/*
 * in RBT every node has either red or black color
 * NULL and root are always black
 * if a node is red then children are black
 * all paths from a node to NULL have same no of black nodes
 * 
 * in RBT two methods are used for balencing
 * 1. Recoloring
 * 2. Rotation
 *
 * Algorithm
 * 1. insert BST
 *      note: by default a node has red color
 * 2. if(x == root) setColour(black)
 * 3. if(x->parent == black) exit
 * 4. if(x != root || x->parent->color == red)
 * 		1. if (x->uncle == red)
 * 			1.setColor of parent and uncle as black
 * 			2. color grandparent red
 * 		2. if (x->uncle == black)
 * 			1. suitable rotation
 *              if LL or RR rotation then recolor
 */

// insertions, updating height, verifying balance factor and perform rotations on AVL trees

struct RBTnode{
    int data;
    short int color;  // 0 - black, 1 - red
    struct RBTnode* left;
    struct RBTnode* right;
    struct RBTnode* parent;
};

node* newNode(int data){
    node* lol = (node*)malloc(sizeof(node));
    lol->data = data;
    lol->color = 0;
    lol->left = NULL;
    lol->right = NULL;
    lol->parent = NULL;
}

node* insertRBT(node* root, int data){
    if(root == NULL)
        return newNode(data);
    if(data < root->data){
        root->left = insertRBT(root->left, data);
        root->left->parent = root;
    }
    else if(data > root->data){
        root->right = insertRBT(root->right, data);
        root->right->parent = root;
    }
    return root;
}

node* rightRotate(node* root, node* temp){
    node* lchild = temp->left;
    temp->left = lchild->right;
    if(temp->left)
        temp->left->parent = temp;
    lchild->parent = temp->parent;
    if(!temp->parent)
        root = lchild; 
    else if(temp->parent->left == temp)
        temp->parent->left = lchild;
    else
        temp->parent->right = lchild;
    lchild->right = temp;
    temp->parent = lchild;
    return root;
}

node* leftRotate(node* root, node* temp){
    node* rchild = temp->right;
    temp->right = rchild->left;
    if(temp->right)
        rchild->left->parent = temp;
    rchild->parent = temp->parent;
    if(!temp->parent)
        root = rchild;
    else if(temp->parent->left == temp)
        temp->parent->left = rchild;
    else
        temp->parent->right = rchild;
    temp->parent = rchild;
    rchild->left = temp;
    return root;
}

void main(){
    // test case for L & R rotation
    node *a = newNode(1),*b= newNode(2),*c= newNode(3);
    a->left=b;
    b->right=c;
    c->parent=b;
    b->parent=a;
    rightRotate(a, a);
    leftRotate(b, b);
    
    return;
}
