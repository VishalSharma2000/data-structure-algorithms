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
    bool checkMirror(TreeNode *head1, TreeNode *head2) {
        if(head1 == NULL && head2 == NULL) return true;
        if(head1 == NULL || head2 == NULL) return false;
        
        return (head1->val == head2->val) && checkMirror(head1->left, head2->right) && checkMirror(head1->right, head2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return checkMirror(root->left, root->right);
    }
};
