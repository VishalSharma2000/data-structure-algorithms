/* Given a string we have to find the number of substring with equal no. of 0s and 1s such that 0s and 1s should come together. */

/* Brute Force Approach: Find all the substrings using two for loop and for each substring found check if it is valid binary substring or not.
If yes then increment count ortherwise continue
Time complexity: (N^3) => (N^2 for finding the substring and N for checking if the string is valid) */

/* Efficient Approach, TC: O(N), SC: O(N) */
/* Since, we want the substring such that all 0s and 1s should come together we will find the count of consecutive 0s and 1s and keep in an array.
To find the substring with both 0s and 1s we can check the consecutive group elements and the minimum of both will be number of valid substrings */
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> g;
        int cnt = 0;
        
        for(int i=0; i<s.length(); i++){
            if(i == 0) {
                cnt = 1;
                continue;
            }
            
            if(s[i-1] == s[i]) {
                cnt++;
            } else {
              // if not equal then push the count of last group and initialize new group count
                g.push_back(cnt);
                cnt = 1;
            }
        }
        // need to push becuase the last group will not terminate automatically
        g.push_back(cnt);
        
        int ans = 0;
        for(int i=1; i<g.size(); i++) {
            ans += min(g[i-1], g[i]);
        }
        
        return ans;
    }
};

/* Space Optimized solution. Rather than storing the count we can store only the prev count and current count becuase at any point we are using only those counts */
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, prev = 0, curr = 1;
        
        for(int i=1; i<s.length(); i++){
            if(s[i-1] != s[i]) {
                ans += min(prev, curr);
                prev = curr;
                curr = 1;
            } else {
                curr++;
            }
        } 
        ans += min(prev, curr);
        
        return ans;
    }
};