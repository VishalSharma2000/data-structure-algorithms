int util(TreeNode *root, int &maxSum) {
  if(!root) return 0;

  int leftSum = util(root->left, maxSum);
  int rightSum = util(root->right, maxSum);

  /* If node has both the child, then choose the sub tree with max sum */
  if(root->left && root->right) {
    /* If current node will not be root then return maxPath to the parent node */
    int temp = max(leftSum, rightSum) + root->val;

    /* Find the sum from one leaf to another with current node as root */    
    int ans = leftSum + rightSum + root->val;

    /* Update the maxSum, if needed */
    maxSum = max(maxSum, ans);
  }

  /* If one of the child does not exist then that node is not leaf node, and to get sum from leaf node we should return the other subtree */
  if(!root->left) return rightSum + root->val;
  else return leftSum + root->val;
}

void maxSumPath(TreeNode *root) {
  int maxSum = INT_MIN;

  util(root, maxSum);

  return maxSum;
}