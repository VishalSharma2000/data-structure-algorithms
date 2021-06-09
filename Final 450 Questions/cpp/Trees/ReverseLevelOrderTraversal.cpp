int getHeight(Node *root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 0;
    
    return (1 + max(getHeight(root->left), getHeight(root->right)));
}

void reverseTraversal(Node *root, int level, vector<int> &ans) {
    if(root == NULL) return; 
    if(level == 0) {
        ans.push_back(root->data);
        return;
    }
    reverseTraversal(root->left, level-1, ans);
    reverseTraversal(root->right, level-1, ans);
}

vector<int> reverseLevelOrder(Node *root)
{
    if(root == NULL) return {};
    
    int height = getHeight(root);
    vector<int> rlot;
    for(int i=height; i>=0; i--)
        reverseTraversal(root, i, rlot);
        
    return rlot;
}