// Brute Force => O(n^2)

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int> nums) {
        if(nums.size() == 0) return NULL;
        if(nums.size() == 1) {
            TreeNode *root = new TreeNode(nums[0]);
            return root;
        }
        
        int maxIndex = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] > nums[maxIndex])
                maxIndex = i;
        }
        
        TreeNode *root = new TreeNode(nums[maxIndex]);
        
        if(maxIndex == 0) {
            root->right = constructMaximumBinaryTree(vector<int> (nums.begin()+1, nums.end()));   
        } else if(maxIndex == nums.size()-1) {
            root->left = constructMaximumBinaryTree(vector<int> (nums.begin(), nums.end()-1));
        } else {
            root->left = constructMaximumBinaryTree(vector<int> (nums.begin(), nums.begin()+maxIndex ));
            root->right = constructMaximumBinaryTree(vector<int> (nums.begin() + maxIndex+1, nums.end()));   
        }
        
        return root;
    }
};
