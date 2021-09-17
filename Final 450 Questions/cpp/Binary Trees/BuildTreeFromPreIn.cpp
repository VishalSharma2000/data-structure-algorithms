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
    /* 
        In preorder traversal, first all the nodes is from left subtree including the node and then all the nodes of the right subtree appreas
        Hence, so for that reason we need to make a global variable to keep track of which index is completed 
     */
    int preIn = 0;
    TreeNode* util(vector<int> &preorder, vector<int> &inorder, int inStart, int inEnd) {
        /* This condition triggers when the node has no children */
        if(inStart > inEnd) return NULL;
        
        TreeNode *head = new TreeNode(preorder[preIn++]);
        
        int in = 0;
        for(in = inStart; in<=inEnd; in++) 
            if(inorder[in] == head->val)
                break;
        
        head->left = util(preorder, inorder, inStart, in-1);
        head->right = util(preorder, inorder, in+1, inEnd);
        
        return head;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return util(preorder, inorder, 0, inorder.size()-1);
    }
};