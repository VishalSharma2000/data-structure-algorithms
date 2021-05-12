#include <bits/stdc++.h>
using namespace std;

/*
  Brute Force approach
  -> Find all the subsequeunce of both the string and then see which subsequence matches.

  Finding the subsequence takes O(2^n) times and comparing will take O(n)
  hence total time complexity will be O(n * 2^n)
*/

int LCSRecursion(string s1, string s2, int n, int m) {
  if(n == 0 || m == 0) return 0;
  /* If any of the one string is empty string then the length of the longest common 
     subsequence is zero */

  if(s1[n-1] == s2[m-1]) return 1 + LCSRecursion(s1, s2, n-1, m-1);

  return max(LCSRecursion(s1, s2, n, m-1), LCSRecursion(s1, s2, n-1, m));
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  LCSRecursion(s1, s2, s1.length(), s2.length());
}