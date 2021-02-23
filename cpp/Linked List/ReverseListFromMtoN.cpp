void reverseList(ListNode *start, ListNode *end) {
	ListNode *curr = start, *currNext = NULL, *prev = NULL;
	
	while(curr != end) {
		currNext = curr->next;
		curr->next = prev;
		prev = curr;
		curr = currNext;
	}
	
	// one iteration will be less
	curr->next = prev;
}

ListNode* reverseBetween(ListNode *head, int m, int n){
	if((m==n) || (head->next) == NULL) return head;
	
	ListNode *leftPrev = NULL, *leftCurr = head;
	ListNode *rightCurr = head, *rightNext = head->next;
	
	// iterate till we reach the mth node from start
	int temp = m;
	while(--temp) {
		leftPrev = leftCurr;
		leftCurr = leftCurr->next;
	}
	
	// iterate till we reach the (n+1)th node from start
	temp = n;
	while(--temp) {
		rightCurr = rightNext;
		if(rightNext)
			rightNext = rightNext->next;
	}
	
	// now reverse between leftCurr and rightPrev
	reverseList(leftCurr, rightCurr);
	
	// after reversing leftCurr will be the tail of the linked list i.e it will move back and
	// rightCurr will move in front
	leftCurr->next = rightNext; 
	if(leftPrev) {
		// if we are reversing the list from 1st node, then their is no leftPrev, hence we need to check whether its null or not
		leftPrev->next = rightCurr;
	} else {
		head = rightCurr;
	}
	
	return head;
}
