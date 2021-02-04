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
    int findLength(ListNode *head) {
        if(head == NULL) return 0;
        
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }
        
        return len;
    }
    
    int getDecimalValue(ListNode* head) {
        int sum = 0;
        int len = 0;
        
        len = findLength(head);
        int i = len-1;
        
        while(head) {
            sum += head->val * pow(2, i);
            i--;
            
            head = head->next;
        }
        
        return sum;
    }
};
