#include <iostream>
using namespace std;
/* Given two numbers m and n, we have to find the greatest common divisor of these nos in log(min(m, n)) complexity */

/* Approach 1 - Brute Force */
/* Traverse from min(m, n) to 1 and keep checking if the number i is dividing both m and n. If yes then it is GCD/HCF
  otherwise continue and at the last 1 will divide both.
  Here we are iterating is descending order because we want to find the greatest divisor
  Time Complexity: O(min(m, n)), Space: O(1) */
int calcGCD(int n, int m){
  if(m == 0 || n == 0)
      return 0;

  int maxRangeOfGCD = min(m, n);
  for(int i=maxRangeOfGCD; i>=1;  i--) {
      if(n%i==0 && m%i == 0)
          return i;
  }

  return 1;
}

/* Approach 2 - Optimised - O(logx(min(m, n)))*/
/* We will use Euclidean algorithm here, which states that gcd(a, b) and gcd(a-b, b) will have the same gcd 
  When we observed closely gcd(a, b) = gcd(a-b, b) = gcd(a-b-b, b)....(till a-y*b < b)..gcd(b, a-y*b)..so on
  so rather than continuosly subtracting we can also write gcd(a, b) = gcd(b, a%b) because a%b = a - (floor(a/b) * b)*/
int calcGCD(int n, int m){
    while(m > 0 && n > 0) {
        if(m > n) m = m%n;
        else n = n%m;
    }

    if(m == 0) return n;

    return m;
}