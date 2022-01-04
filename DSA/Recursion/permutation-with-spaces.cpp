/* Given a string we have to print all permutations by adding spaces between the characters
Eg: s = "ABC" then o/p = {"A B C", "A BC", "AB C", "A B C"} */
#include <iostream>
#include <string>
using namespace std;

void helperPrintPermutation(string in, string ou) {
  if(in.length() == 0) {
    cout << ou << endl;
    return;
  }

  // two decisions - one to take without space and other to take with space
  string ou1 = ou + in[0];
  string ou2 = ou + " " + in[0];

  string newIn = in.substr(1);

  helperPrintPermutation(newIn, ou1);
  helperPrintPermutation(newIn, ou2);
}

void printAllPermutationWithSpaces(string s) {
  /* By output we can see that we don't have to include space at start and end position, so at first we only have one choice i.e. to include first character */
  string ou = s.substr(0, 1);
  string in = s.substr(1);

  helperPrintPermutation(s.substr(1), ou);
}

int main() {
  string s;
  cin >> s;

  printAllPermutationWithSpaces(s);
}