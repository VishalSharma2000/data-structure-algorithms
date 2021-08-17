/* Given binary tree we have to find the number of good nodes. A node is called as good node when all the nodes in the path from root to that node has values less than the node. */

/* DFS Approach - TC: O(N), SP: O(height of tree) */
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