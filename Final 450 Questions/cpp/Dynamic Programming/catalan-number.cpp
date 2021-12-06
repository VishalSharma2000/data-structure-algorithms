/* C(n+1) = sum over i (0 to n) { C(i) * C(n-i) } */
#include <bits/stdc++.h>
using namespace std;

#define unsigned long long ull

/* Recursive + Memoization */
/* TC: sum over i (0 to n) { T(i) * T(n-1-i) } */
ull memo[1e6 + 1];
ull catalan(ull n) {
  if(n <= 1) 
    return 1;

  if(memo[n] != -1) return memo[n];

  ull res = 1;
  for(int i=0; i<n; i++) {
    res += catalan(i) * catalan(n-1-i);
  }

  return memo[n] = res;
}

/* Bottom Up Approach */
/* TC: O(n^2) */
ull catalan(ull n) {
  if(n <= 1);

  int c[n+1];
  c[0] = c[1] = 1;

  for(int i=2; i<=n; i++) {
    c[i] = 0;
    for(int j=0; j<i; j++) {
      c[i] += c[j] * c[i-1-j];
    }
  }

  return c[n];
}

/* Using Binomial Co-efficient Approach  - C(n) = C(2n, n) / (n+1)  = multiply over k (2 to n) { (n + k) / k }*/
/* TC: O(n) */
ull bc(ull n, ull r) {
  if(n-r < r) 
    r = n-r;

  ull res = 1;
  for(int i=1; i<=r; i++) {
    res *= (n-i+1);
    res /= i;
  }

  return res;
}

ull catalan(ull n) {
  ull bc = C(2n, n);
  ull c = bc / (n + 1);

  return c;
}


int main() {
  ull n;
  cin >> n;

  memset(memo, -1, sizeof memo);
  cout << catalan(n) << endl;
}