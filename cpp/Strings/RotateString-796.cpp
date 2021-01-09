/*
if two strings are provided check if one string can be achieved from the other by rotation
*/

#include <iostream>
#include <cstring>

using namespace std;

bool check (string s1, string s2) {
  int len1 = s1.length();
  int len2 = s2.length();

  if(len1 == 0 && len2 == 0) return true;
  if(len1 != len2) return false;

  string temp = s1 + s2;
  for(int i=0; i<temp.length(); i++) {
    if(temp[i] == B[0])
    // if the first character matches find the substr and check if it same or not. 
      if(temp.substr(i, len2) == B) return true;
  }

  return false;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  cout << check(s1, s2) << endl;
}