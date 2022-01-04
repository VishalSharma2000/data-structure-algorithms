#include <bits/stdc++.h>
using namespace std;
/* Time Complexity: O(N), N => size of the string */
/* Worst case space complexity: O(N) to string the final string */

void removeDuplicates(string s) {
  int len = s.length();

  unordered_set<char> alreadyVisited;

  string ans = "";
  for(char ch : s) {
    /* O(1) operation */
    if(alreadyVisited.find(ch) == alreadyVisited.end()) {
      ans += ch;
      alreadyVisited.insert(ch);
    }
  }

  cout << ans << endl;
}

/* Space Optimized */
/* Here we are mainpulating the given string. To keep track of the last index changed we use a variable as pointer */
void removeDuplicates(string s) {
  int len = s.length();

  unordered_set<char> alreadyVisited;

  int i = 0;
  for(char ch : s) {
    /* O(1) operation */
    if(alreadyVisited.find(ch) == alreadyVisited.end()) {
      s[i++] = ch;
      alreadyVisited.insert(ch);
    }
  }

  cout << s.substr(0, i) << endl;
}

int main() {
  string s; 
  cin >> s;

  removeDuplicates(s);
}