/* Below solution is done with taking the reference of dp on trees general syntax but this question can be done in more simple way  */
int solve(TreeNode *root, int &res) {
        /* Base Condition */
        if(!root) return 0;
        
        /* Hypothesis */
        int left = solve(root->left, res);
        int right = solve(root->right, res);
        
        /* Induction */
        /* 
            temp => if current node is not considered as the root of the path then we should return the maximum height of the tree till current node so that
            it can be used to find the diameter for the ancestor nodes
            ans => if current node is considered as the root of the path then the length of the diameter will be sum of height of left sub tree and right sub tree
        */
        
        /* 1 is added for the edge which is connection the left or the right sub tree with the current node
        Note that we used to add another base condition like if(!root->left && !root->right) return 0; if the measurement is done based on the edge and not on the
        node. But here it is not working because in that case we treat the null value and the leaf node at the same height. */
        int temp = max(left, right) + 1;
        int ans = left + right;
  
        /* Keeping track of the final answer */
        res = max(res, ans);
        
        /* Indirectly, Returning the maximum height of the tree till now */
        return temp;
    }
    
int solve2(TreeNode *root, int &res) {
        if(root == null)
                return 0;
        
        int leftHeight = solve2(root->left, res);
        int rightHeight = solve2(root->right, res);
        
        res = max(res, leftHeight + rightHeight);
        
        return max(left, right) + 1; // returning the height
}

    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        
        return res;
    }
