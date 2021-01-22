ListNode* reverseList(ListNode* head) {
        if(!head || (!head->next))  return head;
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        
        while(temp) {
            ListNode *temp1 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = temp1;
        }
        
        return prev;
}

// recursive approach
ListNode* reverseList(ListNode *prev, ListNode *temp) {
        if(temp->next == NULL) {
            temp->next = prev;
            return temp;
        }
        
        ListNode *temp1 = reverseList(temp, temp->next);
        temp->next = prev;
        return temp1;
}