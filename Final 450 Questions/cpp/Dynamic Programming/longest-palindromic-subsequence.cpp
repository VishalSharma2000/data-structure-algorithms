/*
  Given a string, we have to find longest palindromic subsequence in the string. 

  So, we have to find the string which if read from both side make the same word. 

  In lcs type problems, if we are provided with only one string then we should think of some operation in the same string such that it behaves as two different strings.

  So, if we notice properly we have to find the lcs between the reversed string and original string
  So, we have to find lcs(s, reverse(s))
*/

#include <bits/stdc++.h>
using namespace std;

int lpsLen(string s1, string s2, int n, int m) {
  // since m == n
  int dp[n+1][n+1];

  for(int i=0; i<n+1; i++) { dp[i][0] = dp[0][i] = 0; }

  for(int i=1; i<n+1; i++) {
    for(int j=1; j<n+1; j++) {
      if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }

  return dp[n][n];
}

int main() {
  string s;
  cin >> s;
  string s2 = s;
  reverse(s2.begin(), s2.end());

  cout << lpsLen(s, s2, s.length(), s.length());
}