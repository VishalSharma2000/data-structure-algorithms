// Brute Force Approach
bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;
        
        // store the address of the nodes while we are visiting the node, but 
        // before storing check if the node is already visited. If the node is already 
        // visited that means there is a cycle in linked list, else there is no cycle.
        ListNode *temp = head;
        while(temp) {
            if(nodes.find(temp) != nodes.end()) break;
            
            nodes.insert(temp);
            temp = temp->next;
        }
        
        if(temp) return true;
        return false;
    }
// Space Complexity: O(N) 
// Time Complexity: O(N)

// Effiecient Approacy - Using Floyd's Cycle Detection Algorithm
// We will use two pointer, one slow pointer(which will move one node at at time) and fast pointer(which will cover two nodes at at time).
// We will keep updating the two pointer, if at any instance both the pointers point to the same node then their is cycle in the linked list
// or if the fast pointer reaches to NULL value then their is no cycle in the linked list.

bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next) {            
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) break;
        }
        
        if(fast && fast->next) return true;
        return false;
    }
    
    // Time Complexity: O(N) - its actually O(N/2) bcoz fast pointer is moving two nodes at a time...so by the time it will reach the end of node, the slow
    // pointer will reach the middle of the linked list. Hence this method is also used to find the middle of the linked list with only one traversal.
    // Space Complexity :O(1)
