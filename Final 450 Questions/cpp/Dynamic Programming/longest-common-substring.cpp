#include <bits/stdc++.h>
using namespace std;

/* Wrong Answer  */
int LCSubstringRec(string s1, string s2, int n, int m, int res) {
  if(n == 0 || m == 0) return res;

  if(s1[n-1] == s2[m-1]) return res = LCSubstringRec(s1, s2, n-1, m-1, res+1);
  
  return max(res, max(LCSubstringRec(s1, s2, n-1, m, 0), LCSubstringRec(s1, s2, n, m-1, 0)));
}

int LCSubstringDP(string s1, string s2, int n, int m) {
  int dp[n+1][m+1];
  int maxLen = INT_MIN;

  for(int i=0; i<n+1; i++) dp[i][0] = 0;
  for(int j=0; j<m+1; j++) dp[0][j] = 0;

  for(int i=1; i<n+1; i++) 
    for(int j=1; j<m+1; j++) {
      /* Here at dp[i][j] we are not storing longest common substring. we are just maintaining the continuiting of the string. 
      If the character at s1[i] and s2[j] is same then check if the characters i.e. at i-1 and j-1 are same. If they are then add 1 otherwise make it 0 bcoz continuity breaked here */
      if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = 0;

      /* Since, dp[i][j] is just storing the continuity of the string we will have to keep track of the maximum substring so far */
      maxLen = max(maxLen, dp[i][j]);
    }

  return maxLen;
} 

int longestCommonSubstringRecursion(string s1, string s2, int i, int j, int count) {
  if(i == 0 || j == 0) return count;

  if(s1[i] == s2[j]) {
    count = longestCommonSubstringRecursion(s1, s2, i-1, j-1, count+1);
  }

  count = max(count, max(longestCommonSubstringRecursion(s1, s2, i-1, j, 0), longestCommonSubstringRecursion(s1, s2, i, j-1, 0)));

  return count;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  int res = 0;
  cout << LCSubstringRec(s1, s2, s1.length(), s2.length(), res) << endl;
   cout << LCSubstringDP(s1, s2, s1.length(), s2.length()) << endl;
   cout << longestCommonSubstringRecursion(s1, s2, s1.length(), s2.length(), 0) << endl;
}