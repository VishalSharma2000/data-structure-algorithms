int getHeight(Node *node) {
    if(node == NULL) return 0;
    if(node->left == NULL && node->right == NULL) return 1;
    
    return (1 + max(getHeight(node->left), getHeight(node->right)));
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* root) {
    if(root == NULL) return 0;
    
    queue<Node*> q;
    q.push(root);
    int d = INT_MIN;
    
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        
        int h = 1 + getHeight(temp->left) + getHeight(temp->right);
        d = max(d, h);
        
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    
    return d;
}


// O(n) approach
int getDiameter(Node *root, int *height) {
    int lHeight = 0, rHeight = 0;
    int lDiameter = 0, rDiameter = 0;
    
    if(root == NULL) {
        *height = 0;
        return 0;
    }
    
    lDiameter = getDiameter(root->left, &lHeight);
    rDiameter = getDiameter(root->right, &rHeight);
    
    *height = max(lHeight, rHeight) + 1;
    
    return max(lHeight + rHeight + 1, max(lDiameter, rDiameter));
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* root) {
    if(root == NULL) return 0;
    
    int height = 0;
    return getDiameter(root, &height);
}