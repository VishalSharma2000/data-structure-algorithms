#include <bits/stdc++.h>
using namespace std;

/*
  Brute Force approach
  -> Find all the subsequeunce of both the string and then see which subsequence matches.

  Finding the subsequence takes O(2^n) times and comparing will take O(n)
  hence total time complexity will be O(n * 2^n)
*/

#define SIZE 10001
int t[SIZE][SIZE];

int LCSRecursion(string s1, string s2, int n, int m) {
  if(n == 0 || m == 0) return 0;
  /* If any of the one string is empty string then the length of the longest common 
     subsequence is zero */

  if(s1[n-1] == s2[m-1]) return 1 + LCSRecursion(s1, s2, n-1, m-1);

  return max(LCSRecursion(s1, s2, n, m-1), LCSRecursion(s1, s2, n-1, m));
}

int LCSMemoization(string s1, string s2, int n, int m) {
  if(n == 0 || m == 0) return 0;
  if(t[n][m] != -1) return t[n][m];

  if(s1[n-1] == s2[m-1]) return t[n][m] = 1 + LCSMemoization(s1, s2, n-1, m-1);

  return t[n][m] = max(LCSMemoization(s1, s2, n, m-1), LCSMemoization(s1, s2, n-1, m));
}

int LCSTopDown(string s1, string s2) {
  int n = s1.length(), m = s2.length();

  int dp[n+1][m+1];
  for(int i=0; i<n+1; i++) dp[i][0] = 0;
  for(int i=0; i<m+1; i++) dp[0][i] = 0;

  for(int i=1; i<n+1; i++)
    for(int j=1; j<m+1; j++) {
      if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }

  return dp[n][m];
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  cout << LCSRecursion(s1, s2, s1.length(), s2.length()) << endl;

  memset(t, -1, sizeof(t));
  cout << LCSMemoization(s1, s2, s1.length(), s2.length()) << endl;

  cout << LCSTopDown(s1, s2) << endl;
}