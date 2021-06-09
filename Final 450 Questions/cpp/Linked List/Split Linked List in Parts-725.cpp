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
    void insertNode(ListNode *temp, ListNode **head, ListNode **tail) {
        if(*head == NULL) {
            *head = temp;
            *tail = temp;
        } else {
            (*tail)->next = temp;
            *tail = temp;
        }
    }
    
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        // finding the length of the linked list
        int len = 0;
        ListNode *temp = root;
        
        while(temp) {
            len++;
            temp = temp->next;
        }
        
        int rem = len%k;
        vector<pair<ListNode*, ListNode*> > heads(k);
        
        temp = root;
        for(int i=0; i<k && temp; i++) {
            int cond = i < rem ? (len/k) + 1 : (len/k);
            // if(len <= k) cond = 1;
            
            for(int j=0; j<cond; j++) {
                insertNode(temp, &heads[i].first, &heads[i].second);
                temp = temp->next;            
            }
        }
        
        vector<ListNode*> ans;
        for(int i=0; i<heads.size(); i++) {
            // if(i < heads.size()-1) 
            //     heads[i].second->next = heads[i+1].first;
            if(heads[i].second) 
                heads[i].second->next = NULL;
            ans.push_back(heads[i].first);   
        }
        
        return ans;
    }
};
