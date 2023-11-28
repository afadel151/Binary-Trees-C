#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Hashtable {
    int size;
    struct node** chain;
};

struct Hashtable* createHashTable(int size) {
    if(size < 1){
        printf("Hashtable too small");
        return NULL;
    }

    struct Hashtable *table = (struct Hashtable*) malloc(sizeof(struct Hashtable));

    table->chain = (struct node**) malloc(size * sizeof(struct node*));
    for(int i = 0; i < table->size; i++) {
        table->chain[i] = NULL;
    }
    table->size = size;

    return table;
}

void insertInHashtable(struct Hashtable* table, int key) {
    int index = key % table->size;
    struct node* tablePointer = table->chain[index];

    if(tablePointer != NULL) {
        while(tablePointer->next != NULL) {
            tablePointer = tablePointer->next;
        }
        tablePointer->next = createNode(key);
    }
    else
        table->chain[index] = createNode(key);
}

void printHashTable(struct Hashtable* table) {
    for (int i = 0; i < table->size; i++) {
        printf("Chain %d ", i);
        struct node* tablePointer = table->chain[i];
        while(tablePointer != NULL) {
            printf("--> %d ", tablePointer->data);
            tablePointer = tablePointer->next;
        }
        printf("\n");
    }
}

void hashtableTestCase(struct Hashtable* h) {
    for (int i = 0; i < 30; i++) {
        insertInHashtable(h, i);
    }
}

void main() {
    struct Hashtable *h = createHashTable(10);

    hashtableTestCase(h);
    
    printHashTable(h);
}