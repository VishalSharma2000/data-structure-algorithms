/*
  Given 2 string we have to convert string a to b with minimum number of insertion and deletion. 

  On observation, we can see that we only have to insert or delete those characters of the string 
  which are extra or not in order with longest common subsequence.

  So, basically we will first convert the first string into lcs by deleting some characters
  and then
  add some characters to convert the lcs into the string b
*/
#include <bits/stdc++.h>
using namespace std;

int findLCSLen(string s1, string s2, int n, int m) {
  // normal lcs fuctoin
  return 1;
}


int main() {
  string s1, s2;
  cin >> s1 >> s2;

  int lcsLen = findLCSLen(s1, s2, s1.length(), s2.length());

  cout << (s1.length() - lcsLen) + (s2.length() - lcsLen) << endl;
}