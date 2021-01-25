#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    Node *left;
    Node *right;
    int val;

  Node(int data) {
    left = right = NULL;
    val = data;
  }
};

class BST {
  public:
    Node *head;

  BST() {
    head = NULL;
  }

  void insertNode(int val) {
    if(!head)
      head = new Node(val);
    if(!head->left || !head->right)
      if(head->val > val)
        head->left = new Node(val);
      else 
        head->right = new Node(val);
    
    
  }
};

int main() {

}