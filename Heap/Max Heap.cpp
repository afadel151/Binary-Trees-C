#include <iostream>

using namespace std;

struct Heap {
    int size;
    int rear;
    int* heapArray;
};

struct Heap* createHeap() {
    struct Heap* heap = (struct Heap*) malloc(sizeof(struct Heap));
    if(heap == nullptr){
        cout<<"malloc error"<<endl;
        return nullptr;
    }
    heap->size = 5;
    heap->rear = 0;
    heap->heapArray = (int*) malloc(heap->size * sizeof(int));

    return heap;
}

void swap(int *a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void resizeHeap(struct Heap* heap) {
    int oldHeapSize = heap->size;
    heap->size = oldHeapSize * 2;
    int* heapArrayOld = heap->heapArray;

    // heap->heapArray = nullptr;
    heap->heapArray = (int*) malloc(heap->size * sizeof(int));
    for(int i = 1; i <= oldHeapSize; i++) {
        heap->heapArray[i] = heapArrayOld[i];
    }
    free(heapArrayOld);
}



void insertHeap(struct Heap* heap, int data){
    if(heap == nullptr) {
        cout << "Heap not created" << endl;
        return;
    }
    if(heap->size == heap->rear + 1){
        resizeHeap(heap);
    }
    // insert the give element at end
    heap->heapArray[++heap->rear] = data;

    // swap with parent till it reaches its right place
    int dataIndex = heap->rear;
    int parentIndex = dataIndex / 2;
    while(heap->heapArray[dataIndex] > heap->heapArray[parentIndex] && parentIndex > 0){
        swap(&heap->heapArray[dataIndex], &heap->heapArray[parentIndex]);

        dataIndex = parentIndex;
        parentIndex = parentIndex / 2;

    }

}

void printHeap(int *arr, int size) {
    for(int i = 1; i < size; i++) {
        cout<< arr[i] << ' ';
    }
    cout << endl;
}

void insertHeapTestCase(struct Heap* heap) {
    for(int i = 1; i < 10; i++) {
        insertHeap(heap, i);
    }
}

int main() {
    struct Heap* h = createHeap();

    insertHeapTestCase(h);
    printHeap(h->heapArray, h->rear);

    return 0;
}