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


/* Better Solution */
public class Solution {
    
    /**
     * Count the number of prime numbers less than a non-negative number, n
     * @param n a non-negative integer
     * @return the number of primes less than n
     */
    public int countPrimes(int n) {
        
        /**
         * if n = 2, the prime 2 is not less than n,
         * so there are no primes less than n
         */
        if (n < 3) return 0;
        
        /** 
         * Start with the assumption that half the numbers below n are
         * prime candidates, since we know that half of them are even,
         * and so _in general_ aren't prime.
         * 
         * An exception to this is 2, which is the only even prime.
         * But also 1 is an odd which isn't prime.
         * These two exceptions (a prime even and a for-sure not-prime odd)
         * cancel each other out for n > 2, so our assumption holds.
         * 
         * We'll decrement count when we find an odd which isn't prime.
         *
         * If n = 3,  c = 1.
         * If n = 5,  c = 2.
         * If n = 10, c = 5.
         */
        int c = n / 2;
        
        /**
         * Java initializes boolean arrays to {false}.
         * In this method, we'll use truth to mark _composite_ numbers.
         * 
         * This is the opposite of most Sieve of Eratosthenes methods,
         * which use truth to mark _prime_ numbers.
         * 
         * We will _NOT_ mark evens as composite, even though they are.
         * This is because `c` is current after each `i` iteration below.
         */
        boolean[] s = new boolean[n];
        
        /**
         * Starting with an odd prime-candidate above 2, increment by two
         * to skip evens (which we know are not prime candidates).
         */
        for (int i = 3; i * i < n; i += 2) {
            if (s[i]) {
                // c has already been decremented for this composite odd
                continue;
            }
            
            /** 
             * For each prime i, iterate through the odd composites
             * we know we can form from i, and mark them as composite
             * if not already marked.
             * 
             * We know that i * i is composite.
             * We also know that i * i + i is composite, since they share
             * a common factor of i.
             * Thus, we also know that i * i + a*i is composite for all real a,
             * since they share a common factor of i.
             * 
             * Note, though, that i * i + i _must_ be composite for an
             * independent reason: it must be even.
             * (all i are odd, thus all i*i are odd,
             * thus all (odd + odd) are even).
             * 
             * Recall that, by initializing c to n/2, we already accounted for
             * all of the evens less than n being composite, and so marking
             * i * i + (odd)*i as composite is needless bookkeeping.
             * 
             * So, we can skip checking i * i + a*i for all odd a,
             * and just increment j by even multiples of i,
             * since all (odd + even) are odd.
             */
            for (int j = i * i; j < n; j += 2 * i) {
                if (!s[j]) {
                    c--;
                    s[j] = true;
                    }
                }
            }
        return c;
    }
}