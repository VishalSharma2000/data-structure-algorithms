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
    void reverseList(ListNode *head, ListNode *tail) {
        ListNode *prev = NULL;
        ListNode *nextNode = head;
        
        while(head != tail) {
            nextNode = head->next;
            head->next = prev;
            
            prev = head;
            head = nextNode;
        }
        
        head->next = prev;
        
        // return head;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        int len = 0;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            len++;
        }
        
        len = fast ? (len + 1) * 2 : (len * 2) + 1;
        
        /* now slow points to the first middle node(for even length case)*/
        ListNode *temp1 = slow;
        ListNode *temp2 = slow->next;
        
        reverseList(head, slow);
        
        if(len%2 == 1) temp1 = temp1->next;
        
        while(temp1 && temp2) {
            if(temp1->val != temp2->val) return false;
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return true;
    }
};
