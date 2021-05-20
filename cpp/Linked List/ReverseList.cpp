#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            data = val;
            next = NULL;
        }
};

class LinkedList {
    public:
        Node *head; // for pointing the first node of the linked list
        Node *tail; // for pointing the last node of the linked list

        LinkedList() {
            head = NULL;
        }

        Node* reverseUtil(Node *head) {
            if(head == NULL || head->next == NULL) return head;

            // dividing linked list into two parts - first node and rest part
            Node *rest = reverseUtil(head->next);
            /* When the above recursive function ends for first time, then we will be at the second last node of the of the linked list 
            Basically, we are reversing the linked list from last...
            */
            head->next->next = head;
            head->next = NULL;

            return rest;
        }

        void reverseLL() {
            tail = head;
            head = reverseUtil(head);
        }

        void print() {
            Node *temp = head;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;

            return;
        }

        void push(int val) {
            Node *newNode = new Node(val);
            if(head == NULL) {
                head = newNode;
                tail = newNode;
            }

            tail->next = newNode;
            tail = newNode;
        }
};

int main() {
    LinkedList ll;
    for(int i=1; i<=6; i++) ll.push(i * 10);

    ll.print();
    ll.reverseLL();
    ll.print();
}

// ListNode* reverseList(ListNode* head) {
//         if(!head || (!head->next))  return head;
        
//         ListNode* temp = head;
//         ListNode* prev = NULL;
        
//         while(temp) {
//             ListNode *temp1 = temp->next;
//             temp->next = prev;
//             prev = temp;
//             temp = temp1;
//         }
        
//         return prev;
// }

