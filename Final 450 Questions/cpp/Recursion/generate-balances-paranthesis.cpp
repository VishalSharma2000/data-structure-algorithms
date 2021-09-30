#include <iostream>
#include <string>
using namespace std;

void generateBalancedParanthesis(int open, int close, string ou) {
  if(open == 0 && close == 0) {
    cout << ou << endl;
    return;
  }

  if(open > 0) {
    string ou1 = ou + "(";
    generateBalancedParanthesis(open-1, close, ou1);
  }

  if(open < close) {
    string ou1 = ou + ")";
    generateBalancedParanthesis(open, close-1, ou1);
  }
}

int main() {
  int n;
  cin >> n;

  int open = n, close = n;
  string ou = "";

  generateBalancedParanthesis(open, close, ou);
}