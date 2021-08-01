/*
  Given a string we have to find the longest repeating subsequence such that the repeating subsequence should
  have different positions.
*/

#include <bits/stdc++.h>
using namespace std;

int LRSS(string s, int n) {
  int dp[n+1][n+1];

  for(int i=0; i<n+1; i++) dp[i][0] = 0;
  for(int i=0; i<n+1; i++) dp[0][i] = 0;

  for(int i=1; i<n+1; i++) {
    for(int j=1; j<n+1; j++) {
      if((s[i-1] == s[j-1]) && (i != j)) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }

  return dp[n][n];
}

int main() {
  string s;
  cin >> s;

  cout << LRSS(s, s.length()) << endl;
}