/* Leetcode Question: https://leetcode.com/problems/arranging-coins/ */

/* 
row 1 => 1
row 2 => 2
row 3 => 3 and so on...

so total number of coins needed to completely fill k row will be 1 + 2 + 3 + ... + k = k*(k+1) /2

so one way to solve the question is to do a normal O(N) iteration and find the maximum value of k such that k rows are filled...but if we look
closely we can also do a binary search to find the maximum value of k.
i.e. k(k+1)/2 <= n
*/

class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1, high = n;
        int res = -1;
        
        while(low <= high) {
            long long mid = low + (high-low)/2;
            
            long long currCoins = (mid*(mid+1))/2;

            if(currCoins <= n) {
                res = mid;
                low = mid+1;
            } else if(currCoins > n) high = mid-1;
        }
        
        return res;
    }
};