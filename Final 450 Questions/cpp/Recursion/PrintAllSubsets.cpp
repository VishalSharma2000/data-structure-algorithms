#include <bits/stdc++.h>
using namespace std;

void helper(string s, string &subset, int index) {
  cout << subset << endl;

  for(int i=index; i<s.size(); i++) {
    subset.push_back(s[i]);
    helper(s, subset, i+1);
    subset.pop_back();
  }
}

void printSubset(string s) {
  string subset = "";
  int index = 0;

  helper(s, subset, index);
}

int main() {
  string s; cin >> s;

  printSubset(s);
  return 0;
}