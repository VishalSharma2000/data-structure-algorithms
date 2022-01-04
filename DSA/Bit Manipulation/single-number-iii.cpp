/* 
  Given an array of numbers, where all elements except two are repeated twice and those two are repeated once. Find those two elements
  Leetcode Question: https://leetcode.com/problems/single-number-iii/
*/

/* Brute Force approach is very simple. 
  First approach we can use is O(N^2) complexity where for each element we will iterate the array and find the frequency of the element
  if the frequency of the element in 1 then we can store in a varaible. And since we know that only 2 variables are repeated once so after finding those elements we can break the for loop

  int cnt = 0, freq, no1, no2;
  for(int i=0; i<n; i++) {
    freq = 0;
    for(int j=0; j<n; j++) {
      if(arr[j] == arr[i]) freq++;
    }
    if(freq == 1) {
      // store either in no1 or no2
      cnt++;
      if(cnt == 2) break;
    }
  }

  We can optimize the above approach using map<int, int> by storing the frequency or 
  by sorting and then checking which element is repeated and which are not...
  both of this approach will work in O(NLogN) time and O(N) space.

  But here is the main learning bit manipulation technique
*/

/* 
  Let's first find the main problem, we want to return those two element hence to find those elements we need to differentiate between them...
  we have already solved the question where we had to find only one element -> Leetcode Question: https://leetcode.com/problems/single-number-i/
  but here we have to find two elements - so the main point is to find the differentiating factor

  so for that first we are doing the xor of the complete array - so if the two nos are no1 and no2 then the final xor value will be 
  say global xor => gxor = no1 ^ no2

  Now we know that gxor will be zero only when no1 == no2 but that is not the case here, so there will be atleast one set bit in gxor
  and we also know that xor will result into 1 only when one of the bit is set and other is unset...
  hurray!!! if you notice properly we have found the differentiating factor...in one required number a particular bit position(say pos) is set and the same bit position is unset in the second required number

  so we will further divide the array into two set 
  one set will have elements whose pos bit is set 
  and other set will have elements whose pos bit is unset

  for eg: [1, 2, 1, 3, 2, 5]
  gxor = 3^5 = 6 => 110 (here we have two set bits but we can take any one. We will take the rightmost set bit)

  now set1 => {2, 3, 2}
  and set2 => {1, 1, 5}

  Also care about this point - same elements in the original array will also go into same set. Now if we do xor of elements in set1 then we will get the answer as 3 (which is one number) and answer as 5 for set2 which is another number
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        
        int gxor = 0; // global xor for original array
        for(int i=0; i<n; i++) gxor ^= nums[i];
        
        // find the first set bit bcoz that is the differentiating bit between two nos
        int pos = 0;
        while(gxor) {
            if(gxor&1) break; // we only need one diff factor, so break after getting
            
            pos++;
            gxor >>= 1;
        }
        
        // ind variable points to index which was set
        int xor1 = 0, xor2 = 0;
        for(int i=0; i<n; i++) {
          /*  the below is logic to find weather the ith bit is set or not - so we basically create a mask by doing left shift on 1 ith times and do and operation to check if that ith bit is set or not  */
            if(nums[i]&(1<<pos)) xor1 ^= nums[i];
            else xor2 ^= nums[i];
        }
        
        return {xor1, xor2};
    }
};