/* Problem Description: Given a signed 32 bit number we have to reverse the number. If the reversed
  number is more than the maximum possible value signed int can store then return 0 */
#include <iostream>
using namespace std;

/* Approach: Reveresing a number is simple - find the last digit of the number (say lastDigit), multiple 
  the newNumber by 10 and add the lastDigit to it. But since we can only use int (32 bit signed integer) we
  have to figure out a way to detect if the number is crossing [-2^31, 2^31-1], to do that before multiplying
  directly by 10
  
  next_number = next_number * 10 + lastDigit 
  So, next_number * 10 <= INT_MAX 
      next_number <= INT_MAX / 10
      
      Similary next_number >= INT_MIN / 10 */
class Solution {
public:
    int reverse(int x) {
        int reversed_x = 0;

        while (x != 0) {
            if(reversed_x > INT_MAX / 10 || reversed_x < INT_MIN / 10) // preventing for outof bound scenario
                return 0;

            int last_digit = x%10;
            reversed_x = reversed_x * 10 + last_digit;

            x /= 10;
        }

        return reversed_x;
    }
};