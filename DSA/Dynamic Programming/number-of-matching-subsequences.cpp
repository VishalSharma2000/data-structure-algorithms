/* Given a string s and an array of strings, return the count of the strings which are subsequece of the string s */

/* Brute Force Approach */
/* We will find the longest common subsequence between the given string and the ith string of words array. 
  Check if the found longest common subsequence is same as the ith string in words

  To find the longest common subsequence we can use the dynamic programming approach. 
  let n => s.length(), m => size of words array, p => maximum length of the string in words array

  But the time complexity will be O(m * (2*n*p + p))
  For each array find the dp table using lcs method (n*p), contrust the string(n*p) using the table and then reverse it(p)
*/

class Solution {
public:
    bool isLCS(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        
        int dp[n1+1][n2+1];
        
        for(int i=0; i<n2+1; i++) dp[0][i] = 0;
        for(int i=0; i<n1+1; i++) dp[i][0] = 0;
        
        for(int i=1; i<n1+1; i++) {
            for(int j=1; j<n2+1; j++) {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        string lcsStr = "";
        int m = n1, n = n2;
        
        while(m >= 1 && n >= 1) {
            if(s1[m-1] == s2[n-1]) {
                lcsStr += s1[m-1];
                m--;
                n--;
            } else {
                if(m-1 >= 0 && dp[m-1][n] > dp[m][n-1]) {
                    m--;
                } else {
                    n--;
                }
            }
        }
        
        reverse(lcsStr.begin(), lcsStr.end());
        return lcsStr == s2;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt = 0;
        for(int i=0; i<words.size(); i++) {
            if(isLCS(s, words[i])) cnt++;
        }
        
        return cnt;
    }
};

/* Efficient Approach */
/* Store the index of the each character of the given string in a 2d alpha array. 
  Then while traversing for each word in words, check for all character that
  the current character can be found at index that is more than the index position of the previous character
  
  Time Complexity => O(m*p)
    */

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> alpha(26);
        int res = 0;
        
        /* Store the index of each character of the string */
        for(int i=0; i<s.length(); i++) 
            alpha[s[i] - 'a'].push_back(i);
        
        for(string word : words) {
            int last_index = -1;
            bool found = true;
            
            for(char ch : word) {
              /* Upper bound will find the position where the value is strickly greater than the given value */
                auto pos = upper_bound(alpha[ch - 'a'].begin(), alpha[ch - 'a'].end(), last_index);
                /* If no such position exist hence this character is not present */
                if(pos == alpha[ch - 'a'].end()) {
                    found = false;
                    break;
                } else {
                    last_index = *pos;
                }
            }
            
            if(found) res++;
        }
        
        return res;
    }
};