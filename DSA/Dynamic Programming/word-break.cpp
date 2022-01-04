/* Approach: 
The problem statement is to check if we can split the original string into different smaller strings and check if each 
subsegment of string is present in Dictonary array. 
So, the decision of choice we have here is to divide the string of length 1, 2, 3, ..., n-1
so we will take one decision and then call recursively for other string if first segment string is present in dictonary array.

So, the very first approach is to divide the string into two parts of length 1(say segment 1) and n-1(say segment 2) and then check if segment 1 is present in the dict array.
If exist then recursively check for seg2 otherwise continue with greater length segment 1 

Now at each level we have n decisions to make and depth of the recursive tree can be O(N), i.e. by taking string of length one. So, in worst case time complexity will be O(2^n) 

One small optimization which we can do here is to 
- rather than dividing the string from length 1 and to length n-1 we can find the minimum word length and maximum word length available in the dictionary array 

This will not make a much difference in time complexity...
If we look closely we are basically finding substring of the original string so in the recursive tree we will be checking for presence of same string in the dictionary array so we can memomize the overlapping subproblems here using a hash map
Time complexity: (n^2) bcoz total number of substrings will be n^2
*/
class Solution {
public:
    map<string, bool> memo; // for memomization
    int minLen = INT_MAX, maxLen = INT_MIN;
    // hypothesis => this function will check if the string s is present in the dictionary array of not
    bool solve(string s) {
        int n = s.length();
        if(n == 0) return true; // if empty string then present
        if(n < minLen) return false; // if the length of string is less than minimum word length available then definately not available
        
        // if we have already checked that this substring is present or not then return
        if(memo.count(s)) {
            return memo[s];
        }
        
        // check for all possible decisions
        int ans = false;
        for(int i=minLen; i<=maxLen; i++) {
            if(n < i) break;
            string seg1 = s.substr(0, i);
            
            if(memo.count(seg1) && memo[seg1]) {
                ans |= solve(s.substr(i));
                if(ans) return memo[s] = ans;
            } 
            else {
                memo[seg1] = false;
            }
        }
        
        return memo[s] = ans;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        
        memo[""] = true;
        for(int i=0; i<n; i++) {
            memo[wordDict[i]] = true;
            
            minLen = min(minLen, (int) wordDict[i].size());
            maxLen = max(maxLen, (int) wordDict[i].size());
        }
        
        bool ans = solve(s);

        return ans;
    }
    
};