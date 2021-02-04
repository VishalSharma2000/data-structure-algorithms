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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        
        ListNode *prev = NULL;
        ListNode *temp = head;
        
        while(temp) {
            if(prev && temp->val == prev->val) {
                ListNode *temp1 = temp;
                
                prev->next = temp->next;
                temp = temp->next;
                
                delete temp1;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        
        return head;
    }
};
