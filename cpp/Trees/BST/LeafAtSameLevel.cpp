int getHeight(Node *root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 0;
    
    return (1 + max(getHeight(root->left), getHeight(root->right)));
}

bool check1(Node *root, int curr_h, int h) {
    if(root == NULL) return true;
    if(root->left == NULL && root->right == NULL) {
        if(curr_h == h) return true;
        else return false;
    }
    
    return check1(root->left, curr_h+1, h) && check1(root->right, curr_h+1, h);
}

/* You are required to complete this method */
bool check(Node *root)
{
    int height = getHeight(root);
    
    return check1(root, 0, height);
}
