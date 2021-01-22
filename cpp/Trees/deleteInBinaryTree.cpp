void deleteNode(Node *dNode, Node *root) {
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        
        if(temp->left) {
        if(temp->left == dNode) {
            temp->left = NULL;
            delete dNode;
            return;
        } else {
            q.push(temp->left);
        }
        }
        
        if(temp->right) {
        if(temp->right == dNode) {
            temp->right = NULL;
            delete dNode;
            return;
        } else {
            q.push(temp->right);
        }
        }
    }
}
// you are required to complete this function
struct Node* deletionBT(struct Node* root, int key)
{
    if(root == NULL) return NULL;
    if(root->data == key && (!root->left && !root->right)) return NULL;
    
    queue<Node*> q;
    q.push(root);
    
    Node *temp;
    Node *dest = NULL;
    while(!q.empty()) {
        temp = q.front();
        q.pop();    
        
        if(temp->data == key) {
            dest = temp;
        }
        if(temp->left) 
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    
    if(dest != NULL) {
        dest->data = temp->data;
        
        deleteNode(temp, root);
    }
    
    return root;
}