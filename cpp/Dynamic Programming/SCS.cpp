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
  characters only once. And also one thinking is that we should arrange the all characters in such an order that the length
  decreases...so note that those set of characters for which proper ordering will result into less supersequence length
  is the Longest common subsequence. 
  
  So, in the final string we should write the longest common supersequence only once.  */

  return (m + n) - (len);
} 

void printSSS(string s1, string s2, int n, int m) {
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

    cout << s << endl;
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
  printSSS(s1, s2, s1.length(), s2.length());
}