class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head) return NULL;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};