/* Given a lowercase string we need to print all permutation of case changes
INPUT => s = "abc" so
OUTPUT => { ab, aB, Ab, AB } 

INPUT => s = "abc" so
OUTPUT => { abc, abC, aBc, aBC, Abc, AbC, ABc, ABC }*/
#include <iostream>
#include <string>
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

int main() {
  string s;
  cin >> s;

  printAllPermutation(s);
}