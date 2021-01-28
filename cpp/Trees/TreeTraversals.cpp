#include <bits/stdc++.h>
using namespace std;

class Tree {
  public:
  int data;
  Tree *left;
  Tree *right;

  Tree(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};

void inOrder(Tree *root) {
  stack<Tree*> s;

  Tree *curr = root;

  while(!s.empty() || curr) {
    if(curr) {
      s.push(curr);
      curr = curr->left;
    } else {
      curr = s.top();
      s.pop();

      cout << curr->data << " ";
      curr = curr->right;
    }
  }
}

void preOrder(Tree *root) {
  stack<Tree*> s;

  Tree *curr = root;

  while(!s.empty() || curr) {
    if(curr) {
      cout << curr->data << " ";

      s.push(curr);
      curr = curr->left;
    } else {
      curr = s.top();
      s.pop();

      curr = curr->right;
    }
  }
}

void postOrder(Tree *root) {
  stack<Tree*> s;

  Tree *curr = root;

  while(!s.empty() || curr) {
    if(curr) {
      s.push(curr);
      if(curr->right) s.push(curr->right);
      curr = curr->left;
    } else {
      curr = s.top();
      s.pop();
      cout << curr->data << " ";

      // if(curr->right) {
      //   s.push(curr);
      // }
        curr = curr->right;
    }
  }
}

int main() {
	Tree* root = new Tree(1);
	root->left = new Tree(2);
	root->right = new Tree(3);
	root->left->left = new Tree(4);
	root->right->left = new Tree(5);
	root->right->right = new Tree(6);
	root->right->left->left = new Tree(7);
	root->right->left->right = new Tree(8);

  inOrder(root);
  cout << endl;
  preOrder(root);
  cout << endl;
  postOrder(root);
}