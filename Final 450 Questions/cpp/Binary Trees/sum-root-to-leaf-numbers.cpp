/* 
  Leetcode Question: https://leetcode.com/problems/sum-root-to-leaf-numbers/
*/
/* Approach: Basically, we have to traverse all paths from root to leaf which would form a number and add all these numbers.

One thing to note that this question is bit different from the normal tradition recursive tree questions where our recursive hypothesis works for all the subtree of the given tree. So, it works for all root of the subtree but here the now root is the main tree root and we are not continuing the hypothesis for the inner substrees. 

So, we can do a normal DFS to get a path from root to leaf node, for each node in the path we can concat the value to the variable - no string. At last when we encounter a leaf node we can convert this into number and add it to totalSum 

Note: tacking the number as a string is working in this case because each node's value will vary from 0 to 9. If the node can contain 2 or more digit nos then we can go to 2nd approach
*/

// TC: O(N) : N => total number of nodes in the binary tree
class Solution {
public:
    int totalSum = 0; // to store the final answer
    
    void getSumOfLeafNodes(TreeNode *root, string no) {
        if(!root) return; // this if loop will encounter when a node has only one child

        no += to_string(root->val);

        // when encounter a leaf node
        if(!root->left && !root->right) {
            int num = stoi(no);
            totalSum += num;
            
            return;
        }
        
        getSumOfLeafNodes(root->left, no);
        getSumOfLeafNodes(root->right, no);
    }
    
    int sumNumbers(TreeNode* root) {
        string no = "";
        
        getSumOfLeafNodes(root, no);
        
        return totalSum;
    }
};

/* Second Approach: Without using string */
/* Approach: It can be easily seen that we have a form a number, so whenever we go to next digit of the number i.e. to left or right child then multiple by 10 and then add node value to get the final number.  */
// TC: O(N), SC: O(Log(N))
class Solution {
public:
    int totalSum = 0; // to store the final answer
    
    void getSumOfLeafNodes(TreeNode *root, int no) {
        if(!root) return; // this if loop will encounter when a node has only one child

        no = no*10 + root->val;

        // when encounter a leaf node
        if(!root->left && !root->right) {
            totalSum += no;
            
            return;
        }
        
        getSumOfLeafNodes(root->left, no);
        getSumOfLeafNodes(root->right, no);
    }
    
    int sumNumbers(TreeNode* root) {       
        getSumOfLeafNodes(root, 0);
        
        return totalSum;
    }
};