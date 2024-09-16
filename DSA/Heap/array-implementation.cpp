#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;


class MinHeap {
    int *heapArray;
    int cap, size;
public:
    MinHeap(int capacity) {
        cap = capacity;
        heapArray = new int[cap];
        size = 0;
    }
    
    int leftChild(int i) { return (2*i + 1); }
    int rightChild(int i) { return (2*i + 2); }
    int parent(int i) { return (i-1)/2; }
    
    int getMin() {
        if(size == 0) {
            cout << "Error: Heap is empty\n";
            return INT_MAX;
        }
        
        return heapArray[0];
    }
    
    int insertElement(int newElement) {
        if(size == cap) {
            cout << "Heap is already full.";
            return 0;
        }
        
        size += 1;
        heapArray[size-1] = newElement;
        int i = size-1;
        
        while(i != 0 && heapArray[parent(i)] > heapArray[i]) {
            swap(heapArray[parent(i)], heapArray[i]);
            i = parent(i);
        }
        return 1;
    }
    
    int extractMin() {
        if(size == 0) {
            cout << "Error: Heap is empty\n";
            return INT_MAX;
        }
        
        int minElement = heapArray[0];
        heapArray[0] = heapArray[size-1];
        size--;
        Heapify(0);
        return minElement;
    }
    
//     int decreaseKey(int i, int newValue) {
        
//     }
    
//     int deleteKey(int i) {
        
//     }
    
    void Heapify(int i) {
        int left = leftChild(i);
        int right = rightChild(i);
        int smallest = i;
        
        if(left < size && heapArray[left] < heapArray[smallest]) {
            smallest = left;
        }
        
        if(right < size && heapArray[right] < heapArray[smallest]) {
            smallest = right;
        }
        
        if(smallest != i) {
            swap(heapArray[i], heapArray[smallest]);
            Heapify(smallest);
        }
    }
    
    void print() {
        for(int i=0; i<size; i++) {
            cout << heapArray[i] << " ";
        }
        
        cout << endl;
    }
};

int main() {
    MinHeap minHeap(10);
    minHeap.insertElement(10);
    minHeap.print();
    minHeap.insertElement(5);
    minHeap.print();
    minHeap.insertElement(1);
    minHeap.print();
    minHeap.insertElement(3);
    minHeap.print();
    minHeap.insertElement(5);
    minHeap.print();
    minHeap.insertElement(11);
    minHeap.print();
    minHeap.insertElement(4);
    minHeap.print();
    cout<< minHeap.getMin() << endl;
    cout << minHeap.extractMin() << endl;
    minHeap.print();
}