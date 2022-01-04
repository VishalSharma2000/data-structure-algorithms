    void findMinMaxDist(TreeNode *root, int dist, int *minDist, int *maxDist) {
        if(root == NULL) return;
        
        if(*minDist > dist) *minDist = dist;
        if(*maxDist < dist) *maxDist = dist;
        
        findMinMaxDist(root->left, dist-1, minDist, maxDist);
        findMinMaxDist(root->right, dist+1, minDist, maxDist);
    }
    
    void findVerticalOrder(TreeNode *root, int minDist, int maxDist, vector<vector<int> > &ans) {
        if(root == NULL) return;
        
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 0));
         
        while(!q.empty()) {
            vector<vector<int> > tempVec(ans.size(), vector<int> ());
            int size = q.size();
            for(int i=0; i<size; i++) {
                TreeNode *temp = q.front().first;
                int dist = q.front().second;
                q.pop();

                tempVec[dist-minDist].push_back(temp->val);
                
                if(temp->left) q.push(make_pair(temp->left, dist-1));
                if(temp->right) q.push(make_pair(temp->right, dist+1));
            }
            
            for(int i=0; i<ans.size(); i++) {
                sort(tempVec[i].begin(), tempVec[i].end());
                for(int j=0; j<tempVec[i].size(); j++) 
                    ans[i].push_back(tempVec[i][j]);
            }
        }   
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int maxDist = 0, minDist = 0;
        
        findMinMaxDist(root, 0, &minDist, &maxDist);
        
        vector<vector<int> > ans(maxDist-minDist+1, vector<int> ());
        findVerticalOrder(root, minDist, maxDist, ans);
        
        return ans;
    }
};