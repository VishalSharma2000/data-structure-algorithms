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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;
        int nodeValue = 0;
        
        if(root1) nodeValue += root1->val;
        if(root2) nodeValue += root2->val;
        TreeNode* newNode = new TreeNode(nodeValue);
        
        if(root1 && root2) {
            newNode->left = mergeTrees(root1->left, root2->left);
            newNode->right = mergeTrees(root1->right, root2->right);   
        }
        
        if(!root1) {
            newNode->left = mergeTrees(NULL, root2->left);
            newNode->right = mergeTrees(NULL, root2->right);
        }
        
        if(!root2) {
            newNode->left = mergeTrees(root1->left, NULL);
            newNode->right = mergeTrees(root1->right, NULL);
        }   
        
        return newNode;
    }
};

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;
        if(!root1) return root2;
        if(!root2) return root1;
        
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        
        return root1;
    }
};