/*
Recursive way to find Log(n) base m
*/

#include <iostream>
using namespace std;

int findLogNBaseM(int n, int m) {
  if(n == 1) return 0;

  return 1 + findLogNBaseM(n/m, m);
}

int main() {
  int n, m;
  cin >> n >> m;

  cout << findLogNBaseM(n, m) << endl;
  return 0;
}