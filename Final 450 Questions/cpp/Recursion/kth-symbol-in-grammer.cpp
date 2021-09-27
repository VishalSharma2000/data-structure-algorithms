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