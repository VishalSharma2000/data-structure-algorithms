class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        for(char ch : s1) freq[ch - 'a']++;
        
        for(int i=0; i<s2.length(); i++) {
            if(freq[s2[i] - 'a'] > 0) {
                vector<int> temp(freq.begin(), freq.end());
                for(int j=i; j<min(i+s1.length(), s2.length()); j++) {
                    temp[s2[j] - 'a']--;
                }
                
                bool status = true;
                for(int j=0; j<temp.size(); j++) 
                    if(temp[j] != 0) {
                        status = false;
                        break;
                    }
                
                if(status) return true;
            }
        }
        
        return false;
    }
};

/* TC: O(len1 + (len2 - len1)), SC: O(1) */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if(len1 > len2) return false;
        
        vector<int> freq1(26, 0), freq2(26, 0);
        for(int i=0; i<len1; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }
        
        int count = 0;
        for(int i=0; i<freq1.size(); i++) 
            if(freq1[i] == freq2[i]) count++;
        
        for(int i=len1; i<len2; i++) {
            int l = s2[i - len1] -'a', r = s2[i] - 'a'; 
            if(count == 26) return true;
            
            freq2[l]--;
            
            if(freq2[l] == freq1[l]) count++;
            else if(freq2[l]+1 == freq1[l]) count--;
            
            freq2[r]++;
            
            if(freq2[r] == freq1[r]) count++;
            else if(freq2[r]-1 == freq1[r]) count--;
        }
        
        return count == 26;
    }
};

/* Concise solution */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26), freq2(26);
        
        for(char ch : s1) freq1[ch - 'a']++;
        
        for(int i=0; i<s2.size(); i++) {
            freq2[s2[i]-'a']++;
            if(i >= s1.size()) freq2[s2[i-s1.size()]-'a']--;
            
            if(freq1 == freq2) return true;
        }
        
        return false;
    }
};