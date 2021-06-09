/*
Build a stack with O(1) time complexity for the following operations
1) Push
2) Pop
3) Get Middle val
4) Delete Middle val
Note: When size is even, you should return val of floor(n/2), where n is size of stack
*/
#include <bits/stdc++.h>
using namespace std;

class DLL {
  public:
    int val;
    DLL *prev;
    DLL *next;
    
    DLL(int v) {
        val = v;
        prev = NULL;
        next = NULL;
    }
};

class ModifiedStack {
    private:
        DLL *head;
        DLL *tail;
        DLL *middle;
        int size;
    public:
        ModifiedStack() {
            head = NULL;
            middle = NULL;
            size = 0;
        }
    
    void push(int val) {
        DLL *newNode = new DLL(val);
        
        size++;
        
        if(head == NULL) {
            // list is empty
            head = newNode;
            middle = head;
        } else {
            head->next = newNode;
            newNode->prev = head;
            head = head->next;
            
            if(size%2 == 1) {
                middle = middle->next;
            }
        }
    }
    
    int pop() {
        if((head == NULL) || (middle == NULL)) return INT_MIN;
        
        DLL *temp = head;
        int val = temp->val;
        
        head = head->prev;
        size--;
        
        if(size%2 == 0) middle = middle->prev;
        
        delete temp;
        return val;
    }
    
    int getMiddle() {
        if((head == NULL) || (middle == NULL)) return INT_MIN;
        
        return middle->val;
    }
    
    int deleteMiddle() {
        if((head == NULL) || (middle == NULL)) return INT_MIN;
        
        DLL *temp = middle;
        int val = temp->val;
        
        size--;
        
        if(size == 0) { 
            middle = NULL; 
            head = NULL; 
            return val;
        }
        
        middle->next->prev = middle->prev;
        if(middle->prev) 
            middle->prev->next = middle->next;
        
        middle = size%2 == 1 ? middle->next : middle->prev;
        
        delete temp;
        return val;
    }
    
    int getSize() {
        return size;
    }
};

int main() {
    ModifiedStack s;
    
    s.push(5);
    s.push(4);
    cout << s.getMiddle() << endl;
    cout << s.deleteMiddle() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.deleteMiddle() << endl;
    cout << s.deleteMiddle() << endl;
    cout << s.deleteMiddle() << endl;
    cout << s.deleteMiddle() << endl;
}
