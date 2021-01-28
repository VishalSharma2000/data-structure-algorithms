vector<int> leftView(Node *root)
{
    if(!root) return {};
    
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; i++) {
            Node *temp = q.front();
            q.pop();
            
            if(i == 0) ans.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    
    return ans;
}