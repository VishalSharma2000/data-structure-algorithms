/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Recursive approach 
ListNode* reverseK(ListNode *head, int len, int k) {
    if(len - k < 0) return head;
    if(!head) return NULL;
    
    ListNode *current = head;
    ListNode *next = head;
    ListNode *prev = NULL;
    
    int count = 0;
    // Normal way of reversing the linked list
    while(current && count < k) {
        next = current->next; // storing the next node, bcoz the pointer will be changed
        current->next = prev; // updating the link to the previous node
        prev = current;       // re-intialiazing for the next reversal 
        current = next;       // re-intializing for the next reversal
        
        count++;
    }
    
    if(next) {
        head->next = reverseK(next, len-k, k);
    }
    
    return prev;
}

// Iterative approach
ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        for(ListNode *i=head; i!=NULL; len++, i=i->next);
        
        ListNode *dym = new ListNode(0);
        dym->next = head;

        ListNode *prev = dym;
        ListNode *tail = head;

        for(int i=len; i-k>=0; i-=k) {   
            for(int j=1; j<k; j++) {
                ListNode *next = tail->next->next;
                tail->next->next = prev->next;
                prev->next = tail->next;
                tail->next = next;
            }
            
            prev = tail;
            tail = tail->next;
        }
        
        return dym->next;
    }

ListNode* reverseKGroup(ListNode* head, int k) {
    // Finding the length of the linked list
    int len = 0;
    for(ListNode* i=head; i!=NULL;len++, i=i->next);
    
    return reverseK(head, len, k);
}