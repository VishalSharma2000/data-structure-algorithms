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
    int k = 0;
    
    TreeNode* getInorder(vector<int> &preorder, int start, int end, vector<int> &inorder) {
        if(start > end) return NULL;
        
        int rootIndex = -1;
        
        for(int i=start; i<=end; i++) 
            if(preorder[k] == inorder[i]) {
                rootIndex = i;
                break;
            }
        
        TreeNode *root = new TreeNode(preorder[k]);
        k++;
        
        root->left = getInorder(preorder, start, rootIndex-1, inorder);
    
        root->right = getInorder(preorder, rootIndex+1, end, inorder);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return getInorder(preorder, 0, inorder.size()-1, inorder);
    }
};
