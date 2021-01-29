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
            
                int index = level%2 == 1 ? size-1-i : i;
                tempVec[index] = temp->val;
                
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            // if(level%2 == 1) {
            //     reverse(tempVec.begin(), tempVec.end());
            // }
            level++;
            ans.push_back(tempVec);
        }
        
        return ans;
    }
};