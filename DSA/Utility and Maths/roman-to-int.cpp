/* 
  Leetcode Question: https://leetcode.com/problems/roman-to-integer/
  Approach: The only point to note is that whenever we have increasing value in the roman number then we should subtract otherwise add.
  so starting from the back, if we see that s[i] < s[i+1] then we will subtract otherwise add the value
*/
class Solution {
public:
    int romanToInt(string s) {
        int n = (int) s.length();
        
        unordered_map<char, int> mp  = {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };
        
        int ans = mp[s.back()];
        
        for(int i=n-2; i>=0; i--) {
            if(mp[s[i]] < mp[s[i+1]]) {
                ans -= mp[s[i]];
            } else {
                ans += mp[s[i]];
            }
        }
        
        return ans;
    }
};

/* 
  s = "XXIVCM";

  ans = 1000 (M)
  ans = 1000 - 100 (C) because 100 < 1000
  ans = 900 + 5 (V)
  ans = 905 - 1 (I) because 1 < 5
  ans = 904 + 10 (X)
  ans = 914 + 10 (X)

  so final ans = 924
*/