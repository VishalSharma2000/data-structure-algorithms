#include <bits/stdc++.h>
using namespace std;

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
      if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = 0;

      maxLen = max(maxLen, dp[i][j]);
    }

  return maxLen;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  int res = 0;
  cout << LCSubstringRec(s1, s2, s1.length(), s2.length(), res) << endl;
   cout << LCSubstringDP(s1, s2, s1.length(), s2.length()) << endl;
}