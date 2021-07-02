/* Give the number n, find the ordering of numbers from 0 to 2*n-1 such that the binary representation of the numbers in those ordering 
results into gray code */

/* Approach */
/* Basically we have to notice the pattern in the gray codes
  For n = 1 gray codes is {0, 1}
  For n = 2 gray codes is {00, 01, 11, 10}
  For n = 3 gray codes is {000, 001, 011, 010, 110, 111, 101, 100}

  We can obtain the gray code for number n by appending 0 and 1 in the gray codes of n-1.
  So, for n = 3, we can get the first half of gray code by appending 0 at the front of the gray code of 2 (which is n-1)
  and second half of gray code by appending 1 at the front but after reversing the list of array gray code for 2 (which is n-1)
*/
/* 
Total Recursive calls for n=3 will be 3
at each recursive additional work equals 2^n-1

for n=3 total additional work = 2^2 + 2^1 + 2^0 = O(2^n) {Using GP we can find the sum}
Time Complexity: O(2^n) 
*/

class Solution {
public:
    vector<string> getGrayCodes(int n) {
      /* Base or termination condition condition */
        if(n == 1) {
            return {"0", "1"};
        }
        
        /* Get gray codes for n-1 */
        vector<string> grayCodeForPrevNo = getGrayCodes(n-1);
        
        vector<string> ans; // to store the final result
        /* Appending 0 in front to get first half of gray codes */
        for(string s : grayCodeForPrevNo) {
            ans.push_back("0" + s);
        }
        
        /* Appending 1 in front but in reverse order to get second half of gray codes */
        for(int i=grayCodeForPrevNo.size()-1; i>=0; i--) {
            ans.push_back("1" + grayCodeForPrevNo[i]);
        }
        
        return ans;
    }
    
    vector<int> grayCode(int n) {
        vector<string> allGrayCodes = getGrayCodes(n);
        
        vector<int> res;
        /* Convert string to int bcoz we want to return the vector of int */
        for(string s : allGrayCodes) {
            res.push_back(stoi(s, 0, 2));
        }
        
        return res;
    }
};