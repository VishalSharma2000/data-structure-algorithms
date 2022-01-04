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
class Solution {
public:
    void getInorderTraversal(TreeNode *root, vector<int> &inorder) {
        if(root == NULL) return;
        
        getInorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        getInorderTraversal(root->right, inorder);
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int> inorder;
        
        getInorderTraversal(root, inorder);
        
        int minDiff = INT_MAX;
        for(int i=0; i<inorder.size()-1; i++)
            minDiff = min(minDiff, inorder[i+1] - inorder[i]);
        
        return minDiff;
    }
};

// O(n) solution with O(1) space

class Solution {
public:
	// start => bool , used to difference between first node incounter
	// previous => used to store the previous value of the inorder traversal.
    int minDiff = INT_MAX, start = 1, previous;
    
    int minDiffInBST(TreeNode* root) {
        if(root == NULL) return 0;
        
        minDiffInBST(root->left);
        
        if(start) {
        	// this condition will be true, only when the recursion end first time...
        	// eg: going root->left....

            start = 0;
            previous = root->val;
        } else {
            minDiff = min(minDiff, root->val - previous);
            previous = root->val;
        }
        
        minDiffInBST(root->right);
        
        return minDiff;
    }
};
