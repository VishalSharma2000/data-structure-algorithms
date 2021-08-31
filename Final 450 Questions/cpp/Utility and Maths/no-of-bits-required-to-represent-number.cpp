/* Given a number n, find the number of bits required in binary to represent the number OR find the position of the leftmost set bit */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  /* We just to find the number of times the number n can be divided by 2 OR in mathemetical formula this can be represented as
  cnt = ceil(log2(n) + 1) - 
  here while loop is basically finding log2(n) only and 
  since log2(n) will return the number of times n should be divided by 2 to bring it to 1 and 
  we are adding 1 for converting that 1 into 0 (bcoz that last 1 will be the msb) */
  int cnt = 0;
  // loop will run until n does not become 0 (no. of times it runs = log2(n) + 1)
  while(n) {
    n /= 2;
    cnt++;
  }

  cout << cnt << endl;
}