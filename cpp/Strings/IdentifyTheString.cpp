/*
Identify the string is lipogram, pangrametic lipogram or pangram

lipogram => does not contain some set of alphabets
pangram => contain all the letters
pangrametic lipogram => does not contain only one alphabet
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  bool freq[26] = {0};
  for(char ch : s) {
    if(ch >= 'a' && ch <= 'z')
      freq[ch-'a'] = true;
    if(ch >= 'A' && ch <= 'Z')
      freq[ch-'A'] = true;
  }

  int status = 0;
  for(int i=0; i<26; i++) if(freq[i] == false) status++;

  if(status == 1) {
    cout << "Pangrametic Lipogram" << endl;
  } else if(status > 1) {
    cout << "Lipogram" << endl;
  } else {
    cout << "Pangram" << endl;
  }
}