/* Given binary tree we have to find the number of good nodes. A node is called as good node when all the nodes in the path from root to that node has values less than the node. */

/* DFS Approach - TC: O(N), SP: O(height of tree) */
/* Trace the maximum value while traversing the node in dfs approach. For each node compare if the current node's value is more than equal to the maximum value till now. If the value is greater then it is good node otherwise not */
class Solution {
public:  
    int findGoodNodes(TreeNode *root, int maxNode) {
        if(!root) return 0;
        
        int val = 0;
        if(root->val >= maxNode) val = 1;
        
        return val + findGoodNodes(root->left, max(maxNode, root->val)) + 
        findGoodNodes(root->right, max(maxNode, root->val));
    }
    
    int goodNodes(TreeNode* root) {        
        return findGoodNodes(root, root->val);
    }
};

/* BFS Approach - TC: O(N), SP: O(maximum no. of nodes in any level) */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        
        q.push({ root, INT_MIN });
        int count = 0;
        
        while(!q.empty()) {
            TreeNode *curr = q.front().first;
            int prevMax = q.front().second;
            q.pop();
            
            if(curr->val >= prevMax) {
                count++;
            }
            
            if(curr->left) {
                q.push({ curr->left, max(prevMax, curr->val)});
            }
            if(curr->right) {
                q.push({ curr->right, max(prevMax, curr->val)});
            }
        }
        
        return count;
    }
};