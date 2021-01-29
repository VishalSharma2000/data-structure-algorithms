int findBottomLeftValue(TreeNode* root) {        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode *temp = NULL;
        while(!q.empty()) {
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                TreeNode *tempNode = q.front();
                q.pop();

                if(i == 0) temp = tempNode;
                if(tempNode->left) q.push(tempNode->left);
                if(tempNode->right) q.push(tempNode->right);        
            }
        }
        
        return temp->val;
    }