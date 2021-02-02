vector<int> diagonal(Node *root)
{
   if(root == NULL) return {};
   
   vector<int> ans;
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()) {
       int size = q.size();
       
       /*
       Observation: Right childs are always on same diagonal and their left childs are present in the next diagonal.
       So, in the first while loop, we are pushing all the right child of the binary tree...to get the nodes of the current
       diagonal element...
       In the second while loop...we are pushing all the left child for the current diagonal nodes for going to next diagonal.
       */
       
        while(size--) {
            Node* temp = q.front();
            q.pop();
            
            while(temp) {
               ans.push_back(temp->data);
               if(temp->left) q.push(temp->left); 
               
                temp = temp->right;
            }
        }
        
//         size = q.size();
//         while(size--) {
//             Node *temp = q.front();
//             q.pop();
            
//             if(temp->left) q.push(temp->left);
//             ans.push_back(temp->data);
//         }
   }
   
   return ans;
}
