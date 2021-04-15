/*
  Brute Force
*/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len = S.length();
        
        vector<int> ans;
        int upper = 0;
        for(int j=0; j<len; j++) {
            int start = j;
            upper = j;
            for(int i=j; i<=upper; i++) {
                int new_upper = S.find(S[i], i+1);

                if(new_upper > upper) {
                    upper = new_upper;
                    j = new_upper;
                }
            }
            
            ans.push_back(j-start+1);
        }
        
        return ans;
    }
};

/*
  Space and time optimized
*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26];
        int len = S.length();
        
        for(int i=0; i<len; i++) 
            last[S[i] - 'a'] = i;
        
        int start = 0, lastOcc = 0;
        vector<int> ans;
        for(int i=0; i<len; i++) {
            lastOcc = max(lastOcc, last[S[i] - 'a']);
            
            if(lastOcc == i) {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        
        return ans;
    }
};