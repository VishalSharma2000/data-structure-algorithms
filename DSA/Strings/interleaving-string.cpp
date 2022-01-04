/* Given three strings s1, s2 and s3, we have to find if the interleaving of string s1 and s2 will give string s3 */
/* Leetcode Question: https://leetcode.com/problems/interleaving-string/ */

/*
  So here we have two strings whom we have to use and make a new string s3. We have to make use of each character of each string in the order they are appearing.

  eg: s1 = "aabcc", s2 = "dbbca"
  so s3 will be len(s1) + len(s2)
  
  so in total here we will have 10 positions, each position will have two choices one from s1 and one from s2
  so we can recursively try for all the 10 position and at the end of each recursive calls we will get interleaving string and check if the formed 
  string is same as given string s3

  TC: O(2^(m+n)), SC: O(2^(m+n))
*/

/* 
  Another way is match each characters of s3
*/
class Solution {
public:
    int dp[101][101];
    
    bool isInterleaveUtil(string s1, string s2, string s3, int len1, int len2, int len3) {
        if(len1 == 0) return dp[len1][len2] = s2.substr(0, len2) == s3.substr(0, len3);
        if(len2 == 0) return dp[len1][len2] = s1.substr(0, len1) == s3.substr(0, len3);
        
        if(dp[len1][len2] != -1)
            return dp[len1][len2];
        
        // if(s1[len1-1] == s2[len2-1] && s1[len1-1] == s3[len3-1])
        //     return dp[len1][len2] = isInterleaveUtil(s1, s2, s3, len1-1, len2, len3-1) ||
        //     isInterleaveUtil(s1, s2, s3, len1, len2-1, len3-1);
        
        bool ans = false;
        if(s1[len1-1] == s3[len3-1])
            ans |= isInterleaveUtil(s1, s2, s3, len1-1, len2, len3-1);
        
        if(!ans && s2[len2-1] == s3[len3-1])
            ans |= isInterleaveUtil(s1, s2, s3, len1, len2-1, len3-1);
        
        return dp[len1][len2] = ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        
        if(len1 + len2 != len3)
            return false;
        
        memset(dp, -1, sizeof dp);
        
        bool result = isInterleaveUtil(s1, s2, s3, len1, len2, len3);
        
        return result;
    }
};