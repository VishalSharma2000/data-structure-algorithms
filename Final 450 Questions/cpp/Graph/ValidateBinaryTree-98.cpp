/*
  Given the head of the binary tree, we have to validate that the binary tree is valid or not.
  Validity of binary Tree
  1) All the elements in the left subtree of the particular node should be less than that node value
  2) All the elements in the right subtree of the particular node should be more than that node value
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
void getInorderTraversal(TreeNode *root, vector<int> &inorder) {
    if(!root) return;

    getInorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    getInorderTraversal(root->right, inorder);
}

// Brute Force Approach 
/* We know that inorder traversal of the binary search tree is sorted. So, we can find the inorder traversal of the tree and check if the tree is
balanced or not. If the traversal is sorted then the tree is bst otherwise not */
bool isValidBST(TreeNode* root) {
    vector<int> inorder;

    getInorderTraversal(root, inorder);

    for(int i=0; i<inorder.size()-1; i++) 
        if(inorder[i+1] <= inorder[i]) return false;

    return true;
}

int main() {
  takeInput(); // virtual function to take all inputs
  cout << isValidBST(root) << endl;
}
