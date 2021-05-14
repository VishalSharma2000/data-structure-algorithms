#include <bits/stdc++.h>
using namespace std;

string LCS(string s1, string s2, int n, int m) {
  /* Storing the LCS at each stage of the problem */
  string dp[n+1][m+1];

  for(int i=0; i<n+1; i++) {
    for(int j=0; j<m+1; j++) {
      dp[i][j] = "";
    }
  }

  for(int i=1; i<n+1; i++) {
    for(int j=1; j<m+1; j++) {
      if(s1[i-1] == s2[j-1]) {
        dp[i][j] = dp[i-1][j-1] + s1[i-1];
      } else {
        dp[i][j] = dp[i-1][j].length() > dp[i][j-1].length() ? dp[i-1][j] : dp[i][j-1];
      }
    }
  }

  /* By using the normal LCS dp table */
  

  // for(int i=0; i<n+1; i++) {
  //   for(int j=0; j<m+1; j++) 
  //     cout << dp[i][j] << " ";
  //   cout << endl;
  // }

  return dp[n][m];
}

string LCSOptimized(string s1, string s2, int n, int m) {
  int dp[n+1][m+1];

  for(int i=0; i<n+1; i++) dp[i][0] = 0;
  for(int j=0; j<m+1; j++) dp[0][j] = 0;

  for(int i=1; i<n+1; i++) {
    for(int j=1; j<m+1; j++) {
      if(s1[i-1] == s2[j-1])
        dp[i][j] = 1 + dp[i-1][j-1];
      else 
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }

  int i = n, j = m;
  string lcs = "";
  while(i > 0 && j > 0) {
    if(s1[i-1] == s2[j-1]) {
      lcs += s1[i-1];
      i--;
      j--;
    } else {
      if(dp[i-1][j] > dp[i][j-1]) 
        i--;
      else 
        j--;
    }
  }

  reverse(lcs.begin(), lcs.end());
  return lcs;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  cout << LCS(s1, s2, s1.length(), s2.length()) << endl;
  cout << LCSOptimized(s1, s2, s1.length(), s2.length()) << endl;
}