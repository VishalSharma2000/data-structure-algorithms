/* Given a complete binary tree, find the number of nodes in the tree. */

/* Approach: we know that in complete binary tree only the last node is not completed filled and all the other nodes till totalHeight-1 is completely filled. So, if h is the height of the tree then totalNodes till h-1 will be 2^(h-1) */
/* So, first approach is to find the perfect binary tree in the subtrees...so each time we are finding the left height and right height and if they are same then the current tree is perfect tree otherwise we go to left subtree and right subtree */

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
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        TreeNode *leftT = root, *rightT = root;
        int leftH = 0, rightH = 0;
        
        while(leftT) { leftH++, leftT = leftT->left; }
        while(rightT) { rightH++, rightT = rightT->right; }
        
        if(leftH == rightH) return (1 << leftH) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


/* Another more intuitive approach if we think if binary searching the answer
  If we know the height of the tree then we can find the no. of nodes till h-1. So the main problem comes down to finding the no. of nodes in the 
  last level of the tree...so to do that we can use binary search...let's c how...

  each level we have in max 2**h nodes ...so total nodes at height h can be in range [1, 2**h]
  out of which first 2**(h-1) nodes are in left side and other are in right side ...
  so the mid node can be right most node of left subtree
  and left most node of right subtree

  we let midNode = root->left->right->right->right......->right

  if(mideNode == NULL) {
    then we know that the no. of nodes are less than 2**(h-1) so we go to left subtree and find the no. of nodes
  } else if(midNode != NULL) {
    then we know that we have 2**h-1 nodes for sure (so we can add it to the answer) and recurse for right subtree
  }

  we will follow the above thing for all nodes until we get a terminating condition that height == 1 
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
class Solution {
public:
    int countNodesAtLastLevel(TreeNode *root, int height) {
        if(height == 1) {
            // totalHeight = 2
            if(root->right != NULL) return 2;
            else if(root->left != NULL) return 1;
            else return 0;
        }
        
        TreeNode* midNode = root->left;
        int currHeight = 1;
        
        // basically we want to reach the leaf node
        while(currHeight < height) {
            midNode = midNode->right;
            currHeight++;
        }
        
        if(midNode == NULL) return countNodesAtLastLevel(root->left, height-1);
        return (1<<(height-1)) + countNodesAtLastLevel(root->right, height-1);
    }
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return 1;
        
        int height = 0;
        int totalNodes = 0;
        TreeNode *temp = root;
        
        while(temp->left) {
            // iterate till we encounter a leaf node
            totalNodes += (1 << height);
            height++;
            
            temp = temp->left;
        }
        
        // cout << height << endl;
        /* height = total no. of nodes till the 2nd last level */
        return totalNodes + countNodesAtLastLevel(root, height);
    }
};