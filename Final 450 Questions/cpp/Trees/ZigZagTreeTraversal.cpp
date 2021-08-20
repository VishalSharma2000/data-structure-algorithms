/* Given the root of the tree find the zig zag order traversal of the tree */

/* Approach: Do a normal BFS i.e. Level Order Traversal. The only difference here is, when we traverse a odd number level then we need to push
the nodes in the resultant vector in opposite or reverse order. So, for doing this we have two values
1) To traverse the nodes of the level in normal order and store in a vector then at last reverse the vector and push into resultant 2d vector
2) To traverse the nodes of the level in normal order but keep storing the values from the back of the vector, so that the nodes are automatically reversed.  */

/* TC: O(N), SC:O(width of the tree) */
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root == NULL) return {};
    
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    vector<vector<int> > ans;
    
    while(!q.empty()) {
        int size = q.size();
        
        vector<int> tempVec(size);
        for(int i=0; i<size; i++) {
            TreeNode *temp = q.front();
            q.pop();
        
            // store directly from back (way 2)
            int index = level%2 == 1 ? size-1-i : i;
            tempVec[index] = temp->val;
            
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        
        // manual reverse (way 1)
        // if(level%2 == 1) {
        //     reverse(tempVec.begin(), tempVec.end());
        // }
        level++;
        ans.push_back(tempVec);
    }
    
    return ans;
}