class Solution {
public:
    int findMax(TreeNode *root) {
        while(root->right) root = root->right;
        return root->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        
        if(key > root->val) 
            root->right = deleteNode(root->right, key);
        else if(key < root->val)
            root->left = deleteNode(root->left, key);
        else {
            if(root->right == NULL)
                return root->left;
            else if(root->left == NULL)
                return root->right;
            else {
                int maxLeft = findMax(root->left);
                root->val = maxLeft;
                root->left = deleteNode(root->left, maxLeft);
            }
        }
        
        return root;
    }
};
