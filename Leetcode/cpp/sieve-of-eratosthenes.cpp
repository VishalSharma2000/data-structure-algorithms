/*
  Basically, we have to find the number of prime numbers less than n. So, you are given a number n, you have to print all the prime numbers which are less than or equal to n

  Brute force approach where we will check each number is divisible by any prime number then sqrt(n)
  so time complexity: O(n * sqrt(n))

  Time Complexity: O(n * log(log(n)))
  Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
  /*
    In Sieve of Eratosthenes we have a array of size n+1(1 addition, bcoz we want to index till n) and intitialize all with false value.
    We iterate the loop from i=2 and mark all the multiples of 2 as nonPrimes
    then we select the next primes number and mark all its muliples to nonPrimes
    Hence doing this for all the prime numbers less than n will give us the count of prime number
  */

  vector<bool> isPrime(n+1, true);
  int nonPrimeCnt = 0;

  for(int i=2; i<(int) sqrt(n); i++) {
    if(isPrime(i)) {
      for(int j=i*i; j<n; j++) {
        isPrime[j] = false;
        nonPrimeCnt++;
      }
    }
  }

  /*
    Every number can be factorized into mulitple of prime numbers, and the maximum prime number can be sqrt(n)
    for n = 49 => 49 = 7^2
    for n = 50 => 50 = 2 * 5^2

    So, if the number is not divisible by any of the prime numbers less than sqrt(n) then its non prime, hence the outer loop runs only till sqrt(n)

    Secondly, for any prime number n mutiples of it till n-1 can be obtained from less primes numbers
    eg: if 7 is prime number then multiples of it are
    7 * 1 = 7 = 1 * 7
    7 * 2 = 14 = 2 * 7
    7 * 3 = 21 = 3 * 7
    7 * 4 = 28 = 4 * 7 = 2^2 * 7
    7 * 5 = 35 = 5 * 7 
    7 * 6 = 42 = 6 * 7 = 2 * 3 * 7
    7 * 7 = 49 = 7 * 7

    so we can see than all the multipes are covered by smaller primes nos hence the inner loop start from i*i
  */

  // To exclude 1 and n also 
  return (n-2) - nonPrimeCnt;
}

int main() {
  int n; cin >> n;

  cout << countPrimes(n) << endl;
}