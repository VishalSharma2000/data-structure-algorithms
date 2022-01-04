/* Leetcode Question: 476 */

/* 
Idea
Doing an XOR of bit say b with 1 complements the number. So, to complement all the bits of the given number we need to find 111..(to the size equal to num) 

1) Find the total number of bits used to represent the given number. 
2) Make a mask (111....) with the size = noOfBits
  1) One way to do it is (1 << noOfBits) - 1 but this may go overflow because if suppose noOfBits = 31 then doing left shift 31 times will be out of bound for integer. So, we can make use of long long. 
  OR
  2) First do left shift (noOfBits - 1) times and add the mask to itself then do -1.
*/

class Solution {
public:
    int findComplement(int num) {
        int noOfBits = floor(log2(num)) + 1;
        
        int mask = (1 << (noOfBits - 1));
        mask = mask + (mask - 1);
        
        return num ^ mask;
    }
};