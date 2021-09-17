class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        
        root->left = right;
        root->right = left;
        
        invertTree(left);
        invertTree(right);
        
        return root;
    }
};