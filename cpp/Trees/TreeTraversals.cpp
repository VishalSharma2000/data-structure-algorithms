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

int main() {
  Tree *head = new Tree(10);
  head->left = new Tree(20);
  head->right = new Tree(30);
  head->left->left = new Tree(40);
  head->left->right = new Tree(50);
  head->right->right = new Tree(60);
  head->right->right->right = new Tree(70);

  inOrder(head);
}