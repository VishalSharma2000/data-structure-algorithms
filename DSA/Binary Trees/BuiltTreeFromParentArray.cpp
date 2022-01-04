// O(n^2) approach - brute force approach

Node *createTree(int parent[], int N)
{
    int i = 0;
    for(; i<N; i++) {
        if(parent[i] == -1) break;
    }
    
    Node *root = new Node(i);
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        for(int i=0; i<N; i++) {
            if(parent[i] == temp->data) {
                if(temp->left == NULL) {
                    temp->left = new Node(i);
                    q.push(temp->left);
                }
                else if(temp->right == NULL) {
                    temp->right = new Node(i);
                    q.push(temp->right);
                }
            }
        }
    }
    
    return root;
}

// O(n) approach - efficient approach
Node *createTree(int parent1[], int N)
{
    Node* check[N];
    for(int i=0; i<N; i++) check[i] = NULL;
    
    Node* root = NULL;
    for(int i=0; i<N; i++) {
        int parent = parent1[i];
        int child = i;
        
        if(!check[child]) {
            // if child does not exist
            check[child] = new Node(child);
        }
        
        if(parent == -1) {
            root = check[child];
            continue;
        }
        
        if(!check[parent]) {
            check[parent] = new Node(parent);    
        } 
        
        if(!check[parent]->left) {
            check[parent]->left = check[child];
        } else {
            check[parent]->right = check[child];
        }
    }
    
    return root;
}