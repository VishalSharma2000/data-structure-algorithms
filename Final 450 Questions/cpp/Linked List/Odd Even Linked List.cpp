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
    ListNode* oddEvenList(ListNode* head) {
    if((head == NULL) || (head->next == NULL)) return head; 
	ListNode *oddHead = NULL,  *oddTail = NULL;
	ListNode *evenHead = NULL, *evenTail = NULL;
	
	int i = 1;
	ListNode *temp = head;
	
	while(temp) {
		if(i%2 == 1) {
			if(oddHead == NULL) {
				oddHead = temp;
				oddTail = temp;
			} else {
				oddTail->next = temp;
				oddTail = temp;
			}
		} else {
			if(evenHead == NULL) {
				evenHead = temp;
				evenTail = temp;
			} else {
				evenTail->next = temp;
				evenTail = temp;
			}
		}
		
		temp = temp->next;
		i++;
	}
	
	oddTail->next = evenHead;
	evenTail->next = NULL;
	
	return head;        
}
};
