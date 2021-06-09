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
        int temp = max(left, right) + 1;  // height of the current node
  
        /* 
           As per the syntax, the below line should be => ans = max(temp, left + right) but this is not working properly here because
           Daimeter of the tree is defined on the basis of edges not the nodes, and second reason is if diamter is considered from leaf to leaf.
           Since, temp only calculates the maximum height, so it will be either of the left sub tree of right sub tree whose one part will be leaf node but not 
           the other.
        */
        
        int ans = left + right;           // keep track of the maximum diameter obtained so far
  
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
        
        /* If we see closely, we are basically finding the daimeter(longest path) at each node and keep tracking of the maximum diamter obtained so far. 
           We are returning the Height of the tree so far because we are keeping track of the height of the tree simultanously, rather than finding it again and again.
           
           What I mean is: Think of the brute force approach...for each node we will find the height of the left sub tree and height of the right sub tree and then find
           the diameter at that node by adding both of them...so for each node we have to perform getHeight() function which is O(n) so total time complexity
           would rise to O(n^2). So, to avoid to recurring calculation of the height at each node we are keeping track of the height of the current node by returning it.
           
           and the above dp solution is another way of writing the code, wherein we are finding a temporary solution which other ancestor will use to find the answer
           and a answer using the current node...so answer will be use to keep track of the global or main final answer i.e. keeping track of the maximum diamter
           obtained so far and returning the temporary solution (which is height of the node here) so that other nodes can use it.
        */
        
        res = max(res, leftHeight + rightHeight);
        
        return max(left, right) + 1; // returning the height
}

    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        solve(root, res);
        
        return res;
    }
