/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int util(TreeNode *root, int &maxSum) {
    /* Base Case */
    if(!root) return 0;
    
    /* Hypothesis */
    int leftSum = util(root->left, maxSum);
    int rightSum = util(root->right, maxSum);
    
    /* 
    There will be 4 possible paths for each node, 
    1) Left Path = left-max-sum + root->val
    2) Right Path = right-max-sum + root->val
    3) Full Path = left-max-sum + right-max-sum + root->val
    4) Node itself = root->val
     */
    int leftPath = root->val + leftSum;
    int rightPath = root->val + rightSum;
    int fullPath = root->val + leftSum + rightSum;
    
    /* The main section which is breaking the connection with all the descentors if their is commulative sum is negative is finding max between root->val and leftPath and rightPath...if root->val is more than both of them the path one edge will start from root->val */
    
    /* Finding the maxium path sum so far so that the ancestors can use it to find path sum */
    int temp = max(root->val, max(leftPath, rightPath));
    int ans = max(temp, fullPath);
    maxSum = max(maxSum, ans);
    
    return temp;
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    
    util(root, maxSum);
    
    return maxSum;
}