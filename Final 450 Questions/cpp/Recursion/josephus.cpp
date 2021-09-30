/*
Problem statement: If there are n people and you have some number k, so we will skip k-1 people and kill the kth people.
We will continue this iteration until only one person is left on the circular table. So, we should return the last number, which will be left.
*/

#include <iostream>
using namespace std;

int safePosHelper(vector<int> &p, int k, int index) {
  int n = p.size();
  if(n == 1) return p[0];
  
  int nextP = (index + k)%n;
  
  p.erase(p.begin() + nextP);
  
  return safePosHelper(p, k, nextP);
}

int safePos(int n, int k) {
  vector<int> p(n);
  for(int i=0; i<n; i++) p[i] = i+1;
  
  return safePosHelper(p, k-1, 0);
}

int main() {
  int n,k;
  cin >> n >> k;

  cout << safePos(n, k) << endl;
}