/* Leetcode Question: https://leetcode.com/problems/letter-case-permutation/ */
/* Given a lowercase string we need to print all permutation of case changes
INPUT => s = "abc" so
OUTPUT => { ab, aB, Ab, AB } 

INPUT => s = "abc" so
OUTPUT => { abc, abC, aBc, aBC, Abc, AbC, ABc, ABC }*/
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

void printHelper(string in, string ou) {
  // base condition
  if(in.length() == 0) {
    cout << ou << endl;
    return;
  }

  string ou1 = ou; 
  string ou2 = ou;

  ou1 += (char)(in[0] - 32);
  ou2 += in[0];

  string newIn = in.substr(1);

  printHelper(newIn, ou1);
  printHelper(newIn, ou2);
}

void printAllPermutation(string s) {
  string ou = "";

  printHelper(s, ou);
}

void printHelper2(string in, string ou) {
  if(in.length() == 0) {
    cout << ou << endl;
    return;
  }


  if(isdigit(in[0])) {
    string ou1 = ou + in[0];
    printHelper2(in.substr(1), ou1);

    return;
  }

  string ou1 = ou;
  string ou2 = ou;

  ou1 += in[0];
  ou2 += isupper(in[0]) ? tolower(in[0]) : toupper(in[0]);
  string newIn = in.substr(1);

  printHelper2(newIn, ou1);
  printHelper2(newIn, ou2);
}

void printAllPermutationBothCharacter(string s) {
  string ou = "";

  printHelper2(s, ou);
}

int main() {
  string s;
  cin >> s;

  // printAllPermutation(s);
  printAllPermutationBothCharacter(s);
}