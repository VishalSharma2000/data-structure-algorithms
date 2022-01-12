### Given a BST and a value, we have to insert a new node containing the given value. It is given that before and after insertion, each value of the BST is unique.
----

BST follow the below property
1. Each Node in the left sub tree is smaller than the root or parent node.
2. Each Node in the right sub tree is greater than the root or parent node.

**Extra Note: With the above rules we can also say that the inorder traversal of the BST is sorted.**

Since, tree is itself recursive we can solve this question iteratively as well as recursively.
**TC => Best case / Average Case : O(LogN), Worst Case: O(N)**
**SC => Best case / Average Case : O(LogN), Worst Case: O(N), it is basically the call stack space in recursive solution, in iterative solution we have constant space complexity**

### Recursive Solution
```
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        
        if(val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        
        return root;
    }
};
```

### Iterative Solution:
```
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *newNode = new TreeNode(val);
        if(!root) {
            return newNode;
        }
        
        TreeNode *parent = NULL;
        TreeNode *child = root;
        while(child) {
            if(val < child->val) {
                parent = child;
                child = child->left;
            } else {
                parent = child;
                child = child->right;
            }
        }
        
        if(val < parent->val)
            parent->left = newNode;
        else 
            parent->right = newNode;
        
        return root;
    }
};
```

Another Iterative Solution
```
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *newNode = new TreeNode(val);
        if(!root) {
            return newNode;
        }
        
        TreeNode *tempNode = root;
        while(tempNode) {            
            if(val < tempNode->val) {
                if(tempNode->left)
                    tempNode = tempNode->left;
                else {
                    tempNode->left = newNode;
                    break;
                }
            } else {
                if(tempNode->right)
                    tempNode = tempNode->right;
                else {
                    tempNode->right = newNode;
                    break;
                }
            }
        }
        
        return root;
    }
};
```