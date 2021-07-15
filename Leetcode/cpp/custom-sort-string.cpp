class Solution {
public:
    string customSortString(string order, string str) {
        int k = 0;
        vector<int> charOrder(26, -1);
        
        // giving priority to the characters
        for(char ch : order) {
            charOrder[ch - 'a'] = k++;
        }
        for(int i=0; i<26; i++) {
            if(charOrder[i] == -1) charOrder[i] = k++;
        }
        
        // arrange nos as per their priority
        char occOrder[26];
        for(int i=0; i<26; i++) {
            occOrder[charOrder[i]] = i + 'a';
        }
        
        vector<int> freq(26, 0);
        for(char ch : str) freq[ch - 'a']++;
        
        string ans = "";
        for(int i=0; i<26; i++) {
            for(int j=0; j<freq[occOrder[i] - 'a']; j++) {
                ans += occOrder[i];
            }
        }
        
        return ans;
    }
};