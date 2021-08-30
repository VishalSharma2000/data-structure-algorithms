/* Given the number, return true if it is the power of two else return false */
/* Brute Force - O(logn) */
bool isPowerOfTwo(int n) {
  if(n <= 0) return false;

  while(n != 1) {
    /* If at any point n is not divisible by 2 then it is not the power of 2 */
    if(n%2 != 0) return false;

    n /= 2;
  }

  return true;
}

/* For any n, in n-1 the last power of 2 is broken down into smaller powers 
  Eg:
    1 => 0001 , 0 => 0000
    2 => 0010 , 1 => 0001
    3 => 0011 , 2 => 0010
    4 => 0100 , 3 => 0011
    5 => 0101 , 4 => 0100
    6 => 0110 , 5 => 0101
    7 => 0111 , 6 => 0110
    ...
    11 => 1011 , 10 => 1010

    So, if you notice than the last set bit is broken into smaller bits, if the lsb is set then it is removed.
    In case when n is power of 2, there is only one set bit and n&(n-1) will remove that...so for the power of 2
    n&(n-1) should return 0.
*/


/* TC: O(1) */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        
        return (n & (n-1)) == 0;
    }
};