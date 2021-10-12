#include <bits/stdc++.h>
using namespace std;

// TC: O(2^n)

/* The choice or decision which we have to take here is the length of the partition. We can iterate over all the dictionary words and find the minimum length word and the maximum length word which we signify that we should make the string partition of at least minimum word length and till the maximum word length bcoz we are taking less than minimum or more than maximum then definately they that string partition will not be present in the dictionary */
vector<vector<string>> ans;
void wordBreak(string s, vector<string> &wordDict, vector<string> &currString) {
  int n = s.length();
  if(n == 0) {
    ans.push_back(currString);
    return;
  }

  string s1 = "";
  for(int i=0; i<n; i++) {
      s1 += s[i];
      
      if(find(wordDict.begin(), wordDict.end(), s1) != wordDict.end()) {
        currString.push_back(s1);
        wordBreak(s.substr(i+1), wordDict, currString);
        currString.pop_back();
      }
  }
}

int main() {
  string s; 
  s = "iloveicecreamandmango";
  vector<string> dictWord({"mobile","samsung","sam","sung","man","mango", "icecream","and","go","i","love","ice","cream"});

  vector<string> currString;
  wordBreak(s, dictWord, currString);

  for(vector<string> st : ans) {
    for(string val : st) cout << val << " ";
    cout << endl;
  }
}