/* Given two strings, we have to find the shortest common supersequence
eg: s1 = "geek" s2="eke" then shortest common supersequence = geeke */

/* So, the basic idea is to consider those elements which are same in both the string only once. So, basically we have to find the longest common supersequence to get that string. Now other characters in both the strings should be added manually in the final string. So, shortest common supersequence length will be (m + n) - lcs */
#include <bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int n, int m) {
  int dp[n+1][m+1];

  for(int i=0; i<n+1; i++) dp[i][0] = 0;
  for(int i=0; i<m+1; i++) dp[0][i] = 0;

  for(int i=1; i<n+1; i++) {
    for(int j=1; j<m+1; j++) {
      if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }

  return dp[n][m];
}

int lenSCS(string s1, string s2, int n, int m) {
  int len = LCS(s1, s2, n, m);

  /* Which all characters are common in both string, for finding the shortest supersequence we should write those
  characters only once. */
  
  return (m + n) - (len);
} 

/* Print shortest common supersequence */
void printShortestCommonSupersequence(string s1, string s2, int n, int m) {
  /* Print Shortest Super Sequence */
  int dp[n+1][m+1];

  for(int i=0; i<n+1; i++) dp[i][0] = 0;
  for(int i=0; i<m+1; i++) dp[0][i] = 0;

  for(int i=1; i<n+1; i++) {
    for(int j=1; j<m+1; j++) {
      if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }

  int i = n, j = m;
  string s = "";
  while(i > 0 && j > 0) {
    if(s1[i-1] == s2[j-1]) {
      s.push_back(s1[i-1]);
      i--;
      j--;
    } else {
      if(dp[i-1][j] > dp[i][j-1]) {
        s.push_back(s1[i-1]);
        i--;
      } else {
        s.push_back(s2[j-1]);
        j--;
      }
    }
  }

  while(i > 0) {
    s.push_back(s1[i-1]);
    i--;
  }

  while(j > 0) {
    s.push_back(s2[j-1]);
    j--;
  }

  reverse(s.begin(), s.end());

  cout << s << endl;
  return;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  cout << lenSCS(s1, s2, s1.length(), s2.length()) << endl;
  printShortestCommonSupersequence(s1, s2, s1.length(), s2.length());
}