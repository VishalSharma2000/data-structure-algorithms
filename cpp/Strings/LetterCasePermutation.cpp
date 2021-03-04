class Solution {
public:
    void findAllPermutation(string &s, vector<string> &ans, int i) {
        ans.push_back(s);
        
        for(; i<s.length(); i++) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                s[i] = s[i] - 32;
                findAllPermutation(s, ans, i+1);
                s[i] = s[i] + 32;
            } else if(s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] + 32;
                findAllPermutation(s, ans, i+1);
                s[i] = s[i] - 32;
            }
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        
        findAllPermutation(S, ans, 0);
        
        return ans;
    }
};
