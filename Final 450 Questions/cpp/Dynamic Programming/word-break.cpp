/* Approach: Basically divide the string and check if it exist in the dictionary array or not */
class Solution {
public:
    map<string, bool> memo;
    int minLen = INT_MAX, maxLen = INT_MIN;
    bool solve(string s) {
        int n = s.length();
        if(n == 0) return true;
        if(n < minLen) return false;
        
        if(memo.count(s)) {
            return memo[s];
        }
        
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