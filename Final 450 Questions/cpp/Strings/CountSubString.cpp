class Solution {
public:
    int countSubstrings(string s, string t) {      
        int res = 0;
        
        for(int i=0; i<s.size(); i++) {
            for(int j=0; j<t.size(); j++) {
                int miss = 0;
                
                for(int pos = 0; j+pos < t.size() && i+pos < s.size(); ++pos) {
                    if(s[i+pos] != t[j+pos] && ++miss > 1) break;
                    res += miss;
                }
            }
        }
        
        return res;
    }
};
