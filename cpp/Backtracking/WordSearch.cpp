#include <bits/stdc++.h>
using namespace std;

// T(n) = T(n-1) * n + O(k) , k => size of dictWord

// brute force backtracking approach
bool wordBreak(string s, vector<string> &wordDict) {
  int n = s.length();
  
  string s1 = "";
  for(int i=0; i<n; i++) {
      s1 += s[i];
      
      if(find(wordDict.begin(), wordDict.end(), s1) != wordDict.end()) {
          if(i != n-1) {
              if(wordBreak(s.substr(i+1, n-(i+1)), wordDict)) 
                  return true;                    
          }
          else
              return true;
      }
  }
  
  return false;
}

int main() {
  string s; 
  s = "aaaaaaaaaaaaaaaaaab";
  vector<string> dictWord({"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaab"});

  cout << wordBreak(s, dictWord) << endl;
}