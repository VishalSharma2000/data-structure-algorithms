// recursive approach
int findHeight(Node *node) {
    if(node == NULL) return 0;
    if(node->left == NULL && node->right == NULL) return 0;
    
    return (1 + max(findHeight(node->left), findHeight(node->right)));
}

void printLevel(Node *node, int l, vector<int> &ans) {
    if(node == NULL) return;
    
    if(l == 0) {
        ans.push_back(node->data);
        return;
    } else if(l > 0) {
        printLevel(node->left, l-1, ans);
        printLevel(node->right, l-1, ans);
    }
}

vector<int> levelOrder(Node* node)
{
  int height = findHeight(node);
  vector<int> ans;
  
  for(int i=0; i<=height; i++) 
    printLevel(node, i, ans);
    
return ans;
}