/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getAllAncestorsUtil(TreeNode* root, int val, vector<TreeNode*> &ans) {
        if(root == NULL) return false;
        
        if(root->val == val) {
            ans.push_back(root);
            return true;
        }
        
        bool status = getAllAncestorsUtil(root->left, val, ans) || getAllAncestorsUtil(root->right, val, ans);
        
        if(status) ans.push_back(root);
        return status;
    }
    
    vector<TreeNode*> getAllAncestors(TreeNode *root, int val) {
        vector<TreeNode*> ans;
        
        getAllAncestorsUtil(root, val, ans);
        return ans;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> an1(getAllAncestors(root, p->val));
        vector<TreeNode*> an2(getAllAncestors(root, q->val));
        
        for(int i=0; i<an1.size(); i++) {
            for(int j=0; j<an2.size(); j++)
                if(an1[i]->val == an2[j]->val) {
                    return an1[i];
                }
        }
        
        return root;
    }
};
