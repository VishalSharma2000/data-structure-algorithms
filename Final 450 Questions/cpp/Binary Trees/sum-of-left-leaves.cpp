
/* DFS Recursive Approach: 
Basically idea is to consider the node value only when it is the left leaf of the node and then recursively call for all other nodes */
// TC: O(N), SC: (Log(N) OR O(H))
int sumOfLeftLeaves(TreeNode* root) {
    if(!root) return 0;
    
    int sum = 0;
    
    /* If left child exists and it is leaf node then consider it in the sum */
    if(root->left && (!root->left->left && !root->left->right)) sum = root->left->val;
    
    // call for all other nodes
    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

