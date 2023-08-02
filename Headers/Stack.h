#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int* arr;

};

struct stack* createStack(int size){
    struct stack* temp = (struct stack*)malloc(sizeof(struct stack));
    temp->size = size;
    temp->arr = (int*)malloc(sizeof(int)*temp->size);
    temp->top = -1;
    return temp;
}
int isFull(struct stack* s){
    if(s->top+1>=s->size){return 1;}return 0;
}
int isEmpty(struct stack* s){
    if(s->top==-1){return 1;}return 0;
}
void push(struct stack* s,int data){
    if(isFull(s)==1){
        printf("\nCannot Push, Stack is already Full");
        return;
    }
    s->top++;
    s->arr[s->top]=data;
}

void pop(struct stack* s){
    if(isEmpty(s)==1){
        printf("\nCannot Pop, Stack is already Empty");
        return;
    }
    s->top--;

}

void printStack(struct stack* s){
    if(!isEmpty(s)){
        printf("\n");
        for(int i = 0 ; i <=s->top;i++){
            printf("%d ",s->arr[i]);
        }
    }
}
