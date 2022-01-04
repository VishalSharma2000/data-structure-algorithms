/* 
Given a integer x, we need to check if the integer is a palindrome or not
Leetcode Question: https://leetcode.com/problems/palindrome-number/ 
*/

/* 
The very first approach will be to convert the integer into a string and then use the traditional way of checking if the string is palindrome or not. This
approach works fine but it will require some more extra space because we are converting int into string, int takes 4 bytes of space whereas string is stored as an array of characters so in worst case it will take length(INT_MAX) = 9 bytes of space.
So, TC: O(log(x) + 1), SC: (log(x) + 1)

Another approach will be to directly reverse the number x and check if reversedX == x, the problem here is while reversing the number x it may go out of bound of INT_MAX i.e. the number can become greater than INT_MAX which will create overflow problem.
We can definitely use long long to store the reversed number but that will again take 8 bytes of space, so even though it's not dependent on the input integer we are using some extra space here also.

So, as we know the property of palindrome is - given an string s of length n then first half of the string i.e. s.substr(0, n/2) equals the reverse of second half of the string i.e. reverse(s.substr(n/2, n/2))
So, we can try the same here, we will only reverse the second half of the integer which will definitely not go out of bound and then check if the first half equals the second half
*/
class Solution {
public:
    bool isPalindrome(int x) {
        /* All negative nos can't be palindrome and if the last digit of the number x is 0 then x will be palindrome only when it is itself 0 because given input x will not have leading zeros */
        if(x < 0 || (x%10 == 0 && x != 0)) 
            return false;
        
        int revSecondHalf = 0;
        /* Here basically we are dividing x (with d digit) into two nos with d/2 and d/2 digit because x will be greater than revSecondHalf till the number of digit in x is more that number of digit in revSecondHalf, when both the nos have the same digit then definitely they should be same if x is palindrome otherwise while loop will break */
        while(x > revSecondHalf) {
            revSecondHalf = revSecondHalf * 10 + (x % 10);
            
            x /= 10;
        }
        
        /* the second condition is to handle the case when x has odd number of digits */
        return (x == revSecondHalf || x == (revSecondHalf / 10));
    }
};