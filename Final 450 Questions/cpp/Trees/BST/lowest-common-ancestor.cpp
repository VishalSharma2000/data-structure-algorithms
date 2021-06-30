/* Given the tree T, node p and node q. Find the Lowest Common Ancestor */
/* 
  Approach 1:
    This is the brute force approach. 
    For each node 
    check if the node itself is either of the two nodes
      If yes then 
        check if the second node lies in the left subtree or right subtree. If exist then current node is LCA
    Else if current node is not equal to any of the nodes then
      check if p exist in left subtree AND q exist in right subtree OR p exist in right subtree or q exist in left subtree.
      If the above condition is true. That current node will be our LCA
    Else
      Call Recursively for left and right subtree
*/

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
    /* 
      For each node we are traversing the whole array to find the existance of the node. To find a node in tree takes log(n) time.
      Hence for all n nodes time complexity will be O(n Log(N))
      Time Complexity: O(nLog(n))
     */

    bool checkIfExist(TreeNode *root, TreeNode *p) {
        if(!root) return false;
        if(!p) return false;
        
        if(root == p) return true;
        
        if(checkIfExist(root->left, p)) return true;        
        if(checkIfExist(root->right, p)) return true;
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        
        if(root == p) {
            if(checkIfExist(root->left, q) || checkIfExist(root->right, q)) return root;
        } else if(root == q) {
            if(checkIfExist(root->left, p) || checkIfExist(root->right, p)) return root;
        } else {
            // p in left and q in right
            if(checkIfExist(root->left, p) && (checkIfExist(root->right, q))) return root;
            // p in right and q in left
            else if(checkIfExist(root->right, p) && checkIfExist(root->left, q)) return root;
            else {
                // call recusively for further nodes
                TreeNode *left = lowestCommonAncestor(root->left, p, q);
                if(left) return left;
                
                TreeNode *right = lowestCommonAncestor(root->right, p, q);
                if(right) return right;
            }
        }
        
        return NULL;
    }
};


/* 
  The problem with the above approach is each node is traversed more than onces. If you see clearly then for each node we are 
  traversing the whole array again and again for finding the same nodes p and q. So, here the idea is to try to do both things 
  in the same recursive call

  Idea:
    You would have understood that there are four condition for checking if the current node is lcs for p and q. If any of the
    condition is true then its lca.

    currnode is equal to p and q is found in right subtree
    currnode is equal to q and p is found in left subtree
    p is found in left or q is found in right
    q is found in right or q is found in left

    In the above solution each node is traversed only once. Hence the time complexity will be O(n)
*/


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
    TreeNode *ans = NULL;
    
    // will return all ancestors 
    bool preOrderTraversal(TreeNode *root, TreeNode *p, TreeNode *q) {
        if(root == NULL) return false;
        
        bool curr = false, left = false, right = false;
        
        // check if any of the nodes is equal to either q or p
        curr = root == p || root == q;
        
        // recursively check if the left subtree contain any of the one node
        left = left || (preOrderTraversal(root->left, p, q));
        // recursively check if the right subtree contain any of the one node
        right = right || (preOrderTraversal(root->right, p, q));
        
        // if any of the condition is true save the ancestor
        if((curr && right) || (curr && left) || (left && right)) {
            ans = root;
        }
        
        return curr || left || right;   
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        preOrderTraversal(root, p, q);
        
        return ans;
    }
};

/* More concise solution */

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
    TreeNode *ans = NULL;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;
        
        if(root == p || root == q) return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        // if both the nodes are found 
        if(left && right) return root;
        
        return left ? left : right;
    }
};


/* Another Approach */
/* Basically finding all the ancestors of two nodes separately and then finding the first common ancestors */

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
