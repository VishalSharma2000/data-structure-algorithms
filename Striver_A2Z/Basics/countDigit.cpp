/* Problem Description: Given a integer number n we have to find the total number of digits it has */

#include <iostream>
using namespace std;

/* Approach 1 */
/* We can continuously divide the number by 10 until it becomes zero. In each iteration we can increment a variable 
   which will tell the total number of digits in the number n */

/* Time Complexity: O(log10(n)), Space Complexity: O(1)*/
int countDigits(int n) {
  int totalDigits = 0;

  while (n != 0) {
    n /= 10;

    totalDigits++;
  }

  return totalDigits;
}

/* Approach 2 */
/* Convert the given number into string and then count the length of the string */
int countDigits(int n) {
  string n_inString = to_string(n);

  return n_inString.length();
}