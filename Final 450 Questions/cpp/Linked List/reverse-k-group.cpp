/* Leetcode Question: https://leetcode.com/problems/reverse-nodes-in-k-group/ */

/* 
Problem Statement: Given the linked list and an interge k, we have to reverse all groups of k linked list. If the last group has less than k nodes then reverse that group also. (this is on gfg)
List: 1->2->3->4->5 , k = 3 then reversing will give List: 3->2->1->5->4 

There is another variation (this is on leetcode)
Problem Statement: Given the linked list and an interge k, we have to reverse all groups of k linked list. If the last group has less than k nodes then skip that group.
List: 1->2->3->4->5, k =3 then reversing will give List: 3->2->1->4->5
*/

/* In case of leetcode variation we also have to check if the remaining number of nodes are more than or equal to k then only the function should proceed further and reverse the group otherwise skip it and return head whereas
in gfg variation we neednot check this extra condition and always reverse the linked list */

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

/* A more intuitive approach, O(N) time complexity (2 pass) */
class Solution {
public:
    ListNode* reverseLL(ListNode *head) {
        if(!head) return head;
        
        ListNode *prev = NULL, *temp = head;
        while(temp) {
            ListNode *nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        
        ListNode *start = head, *end = head;
        int cnt = 1;
        
        // check if the group of k nodes exist or not
        while(end && end->next && cnt < k) {
            end = end->next;
            cnt++;
        }
        
        // if does not exist then return
        if(cnt != k) return head;

        // make connections to reverse the linked list
        ListNode *nextNode = end->next;
        end->next = NULL;
     
        reverseLL(start);
        start->next = reverseKGroup(nextNode, k);
        return end;
    }
};

// Recursive approach (more concise way of writing the above code) - O(N) time complexity (2 pass)
ListNode* reverseK(ListNode *head, int len, int k) {
    if(len - k < 0) return head; // if no. of nodes are less than k then return
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
    
    /* We need reversing here because we need to connect the start (which will be end after reversing) to the end of the next group, so we are basically reversing recursively and obtaining the connection */
    head->next = reverseK(next, len-k, k);
    
    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    // Finding the length of the linked list
    int len = 0;
    for(ListNode* i=head; i!=NULL;len++, i=i->next);
    
    return reverseK(head, len, k);
}

// Iterative approach
ListNode* reverseKGroup(ListNode* head, int k) {
  int len = 0;
  for(ListNode *i=head; i!=NULL; len++, i=i->next);
  
  /* check your notes */
  ListNode *dummy = new ListNode(0);
  ListNode *prevEnd = dummy;
  ListNode *start = head, *end = head, *prev = NULL;
  
  for(int i=len; i-k>=0; i-=k) {   
      for(int j=0; j<k; j++) {
          ListNode *nextNode = end->next;
          end->next = prev;
          prev = end;
          end = nextNode;
      }
      
      prevEnd->next = prev;
      prevEnd = start;
      
      start = end;
      prev = NULL;
  }
  prevEnd->next = end;
  
  return dummy->next;
}