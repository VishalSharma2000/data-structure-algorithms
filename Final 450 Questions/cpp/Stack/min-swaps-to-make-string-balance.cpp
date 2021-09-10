/* 
  Leetcode Question: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
*/

/* Approach: We have to find minimum number of swaps to make the string balance. First let's see what characters we will swap to get the string
to balance point. 
In total we have 4 cases
1 => [[, 2 =>  [], 3 => ][, 4 => ]] 
Doing operation 1 2, and 4 will be of no use becuase they will make no difference in the original string. we will perform 3rd operation.

So, a string will be in unbalance state only when no. of closing > no. of opening brackets at any point. 

0 1  2 3  4  5 6  7
[ ]  ] ]  [  [ ]  [
1 0 -1 -2 -1 0 -1 0

at index 2, no. of closing > no. of opening so we can swap it will be first opening bracket from the last. Why do we swap with the opening from last i.e. bcoz we need to balance the string and in a balanced string ] should be after [ so in the case when we are swapping with the first opening from last we are basically sending the closing at the last only hence brackets will automatically get balanced...

the below string is also balanced so we don't have to worry about how the string will look after balance bcoz
[][] and [[]] both are balanced string only ...so by swapping the unbalanced closing with the first opening from last we are trying to achieve the 2nd case...

[[[[[....]]]]]

here we don't have to return the final string we just have to find the no. of swaps ...so by drying running different cases we can see that
total unbalanced closing bracket      swaps
1                                       1
2                                       1
3                                       2
4                                       2
5                                       3
6                                       3
7                                       4
and so on.

no. of swaps = ceil(total unbalanced closing brackets / 2)
*/

class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0;
        int balance = 0;
        
        for(int i=0; i<s.size(); i++) {
            char ch = s[i];
            
            if(ch == '[') {
                balance++;
            } else {
                if(balance) {
                    balance--;
                } else {
                    cnt++;
                }
            }
        }
        
        return (cnt+1)/2;
    }
};