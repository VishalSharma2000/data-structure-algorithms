/*
Problem statement: If there are n people and you have some number k, so we will skip k-1 people and kill the kth people.
We will continue this iteration until only one person is left on the circular table. So, we should return the last number, which will be left.
*/

#include <iostream>
using namespace std;

int josephus(int n, int k) {
  if (n == 1) return 1;

  int killedPerson = josephus(n-1, k);
  // will return the index, according to n-1 person, so for using it in the case where n people are alive, we should adjust the index

  int actualIndex = (killedPerson + k-1) % n + 1;

  return actualIndex;
}

int main() {
  int n,k;
  cin >> n >> k;

  cout << josephus(n, k) << endl;
}