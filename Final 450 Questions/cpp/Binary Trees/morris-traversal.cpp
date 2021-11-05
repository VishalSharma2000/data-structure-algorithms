/* The main idea behind morris traversal is based on threaded binary tree, basically we make connections such that usage of stack is eliminated */
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
  public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int v) {
    val = v;
    left = right = NULL;
  }
};

void inorderTraversal(TreeNode *head) {
  if(!head) return;

  inorderTraversal(head->left);
  cout << head->val << " ";
  inorderTraversal(head->right);
}

void morrisTraversal(TreeNode *head) {
  if(!head) return;

  TreeNode *current = head;

  while(current != NULL) {
    // this if loop will be executed when we finish exploring the left subtree of the current node
    if(!current->left) {
      cout << current->val << " ";
      current = current->right;
    } else {
      TreeNode *pre = current->left;

      // find inorder predecessor the current node
      while(pre->right && pre->right != current) {
        pre = pre->right;
      }

      if(pre->right == NULL) {
        /* Make the current node the right child of the inorder predecessor (or right most child of the left subtree of current) */
        pre->right = current;
        current = current->left;
      } else {
        /* Revert the connections made in the above if part to get the original tree back */
        pre->right = NULL;
        cout << current->val << " ";
        current = current->right;
      }
    }
  }
}

int main() {
  TreeNode *head = new TreeNode(1);
  
  // left subtree
  head->left = new TreeNode(2);
  head->left->left = new TreeNode(6);
  head->left->left->left = new TreeNode(7);
  head->left->left->right = new TreeNode(8);

  // right subtree
  head->right = new TreeNode(3);
  head->right->left = new TreeNode(4);
  head->right->right = new TreeNode(5);


  inorderTraversal(head);
  
  cout << endl;

  morrisTraversal(head);
}