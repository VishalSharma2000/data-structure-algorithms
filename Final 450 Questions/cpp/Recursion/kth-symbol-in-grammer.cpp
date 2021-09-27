/* Leetcode Question: https://leetcode.com/problems/k-th-symbol-in-grammar/ */
/* By Observation we can see that for nth row the total number of elements are 2^(n-1). First half of the elements are same as the previous row elements and next half of the elements are complement of the first half of previous row */
/* 
0
0 1
0 1 1 0
0 1 1 0 1 0 0 1
0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
...
*/

// TC: O(N)
class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1) return 0;
        
        int size = (1 << (n-1));
        if(k <= size/2) return kthGrammar(n-1, k);
        else return !kthGrammar(n-1, k - (size/2));
    }
};

/* Another approach to solve this question is to amazing the grammer as a binary tree. SO the root is 0 and each node has 2 childs or 0 childs. If node value is 0 then left child is 0 and right child is 1 and if node value is 1 then left child is 1 and right child is 0. So we can find the parent and accordinly we can find the kth value in the nth row */
/* Another observation => if k%2 == 0 then it's right child and the parent in previous row is k/2 otherwise left child and it's parent in previous row is (k+1)/2. */
class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;
        
        if(k%2 == 0) {
            return kthGrammar(n-1, k/2) == 0 ? 1 : 0;
        } else {
            return kthGrammar(n-1, (k+1)/2) == 0 ? 0 : 1;
        }
    }
};