#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int input){
        this->left = NULL;
        this->right = NULL;
        this->data = input;
    }
};

class binaryTree{
    public:
    node* root;

    binaryTree(int data){
        this->root = new node(data);
    }
    bool empty(){
        if(this->root == NULL){
            cout<<"Tree is empty"<<endl;
            return true;
        }
        else return false;
    }
    node* insertLevelOrder(node* root, vector<int> arr, int index, int arrSize){
        if(index<arrSize){
            node* temp = new node(arr.at(index));
            root = temp;
        root->left = insertLevelOrder(root->left, arr, (2*index+1), arrSize);
        root->right = insertLevelOrder(root->right, arr, (2*index+2), arrSize);
        }
        return root;
    }
    void inorderNR(){
        if(empty())
            return;

        cout<<"InOrder Traversal: ";
        stack<node*> st;
        node* current = this->root;
        while(current != NULL || !st.empty()){
            while(current != NULL){
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            cout<<current->data<<" ";
            current = current->right;
        }
        cout<<endl;
    }

    void preorderNR(){
        if(this->root == NULL)
            return;
 
        cout<<"PreOrder Traversal: ";
        stack<node*> st;
        node* current = this->root;
        st.push(current);
            while(!st.empty()){
                current = st.top();
                st.pop();
                cout<<current->data<<" ";
                if(current->right != NULL)
                    st.push(current->right);
                if(current->left != NULL)
                    st.push(current->left);
            }
        cout<<endl;
    }
    void postorderNR(){
        if (empty())
            return;

        cout<<"PostOrder Traversal: ";
        stack<node*> s1;
        stack<node*> s2;
        s1.push(root);
        while (!s1.empty()) {
            node* current = s1.top();
            s1.pop();
            s2.push(current);

            if (current->left)
                s1.push(current->left);

            if (current->right)
                s1.push(current->right);
        }
        while (!s2.empty()) {
            node* current = s2.top();
            s2.pop();
            cout << current->data << " ";
        }
        cout<<endl;
    }
};

int main(){
    binaryTree *bt = new binaryTree(1);

    vector<int> arr = {1,2,3,4,5,6,7};
    bt->root = NULL;
    bt->root = bt->insertLevelOrder(bt->root, arr, 0, arr.size());

    bt->inorderNR();
    bt->preorderNR();
    bt->postorderNR();
    return 0;
}