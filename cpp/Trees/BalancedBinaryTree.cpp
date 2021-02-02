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
 
 Brute Force: 
 For each node, find the height of the left subtree and find height of right subtree...find the absolute difference and check if the abs diff is more
 than 1 then return false(tree is not balanced)
 else return true(tree is balanced)
 Time complexity: O(n^2)
 
 Efficient Approach: 
 We will find the height in the same recursive call.
 Logic: pass the height variable's address as parameter and find the height.
 Time complexity: O(n)
 
class Solution {
public:
    bool checkBalance(TreeNode *root, int *height) {
        if(root == NULL) {
            *height = 0;
            return true;
        }
        
        int leftH = 0, rightH = 0;
        bool leftB = checkBalance(root->left, &leftH);
        bool rightB = checkBalance(root->right, &rightH);
        
        *height = 1 + max(leftH, rightH); // helps in finding height
//         if(abs(leftH-rightH) > 1) return false;
        return leftB && rightB && (abs(leftH-rightH) <= 1);
     // left subtree, right subtree should be balanced and height difference between the left subtree and right subtree should be less than or equal to 1.
    }
    
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        int height = 0;
        return checkBalance(root, &height);
    }
};
