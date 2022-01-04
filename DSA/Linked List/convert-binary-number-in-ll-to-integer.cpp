/* Leetcode Question: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/ */
/* Given a linked list having values either 0 or 1 we have to find the integer number */

/* 
  The intuitive approach is to find the length of the linked list and then traverse the linked list again and multiply by 2^(len - i) whenever 1 is encountered in node value.
  Time complexity: O(N) => but we are doing two pass in the linked list
  Space Complexity: O(1)
*/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int len = 0;
        ListNode *temp = head;
        
        while(temp) {
            len++;
            
            temp = temp->next;
        }
        
        int res = 0, i = 1;
        temp = head;
        while(temp) {
            res += temp->val * (1 << (len-i));
            i++;
            temp = temp->next;
        }
        
        return res;
    }
};

/* 
  We can do more better by understanding how bits work.
  Multiply a number by 2 basically mean shifting the bits of the binary representation by 1 (equivalent to doing left shift by 1)
  eg: no = 25 , binary => 11001
      no*2 = 50, binary => 110010

  so we can initially assume the number to be 0 and 
  note that the number of bits in the final binary representation will be equal to the length of the linked list.
  So, in each iteration do a left shift by 1 or multiply by 2 to shift the bits to left and
  whenever encounter 1 add it in the number or do OR operation
*/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        ListNode *temp = head;
        
        while(temp) {
            // with bits (works faster)
            res = (res << 1) | (temp->val);
            
            // with nos (works comparatively slower than bits)
            res = (res * 2) + (temp->val);
            temp = temp->next;
        }
        
        return res;
    }
};
