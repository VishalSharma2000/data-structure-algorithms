/* Leetcode Question: https://leetcode.com/problems/add-binary/ */
/* Given two binary strings, we have to return the sum of the binary string. */

/* First simple approach is to convert the string into decimal number, add those decimal nos and then again convert the decimal number into binary string. This approach will not work here because the constraint for binary string is given as [0, 10^4]. 
We can't represent binary string of length more than 64 bits as a decimal number. So, it's sure that we have to directly perform the binary addition on these binary strings. */

/* Approach 2: Perform binary addition */
class Solution {
public:
    int getDecimal(char ch) {
        return ch - '0';
    }
    
    string addBinary(string a, string b) {
        int p1 = a.length() - 1, p2 = b.length() - 1;
        
        int sum = 0, cry = 0;
        string ans = "";
        while(p1 >= 0 && p2 >= 0) {
            int bit1 = getDecimal(a[p1]), bit2 = getDecimal(b[p2]);
            
            sum = (bit1 + bit2 + cry)%2;
            cry = (bit1 + bit2 + cry)/2;
            
            ans.push_back(sum + '0');
            
            p1--, p2--;
        }
        
        while(p1 >= 0) {
            int bit = getDecimal(a[p1]);
            
            sum = (bit + cry)%2;
            cry = (bit + cry)/2;
            
            ans.push_back(sum + '0');
            
            p1--;
        }
        
        while(p2 >= 0) {
            int bit = getDecimal(b[p2]);
            
            sum = (bit + cry)%2;
            cry = (bit + cry)/2;
            
            ans.push_back(sum + '0');
            
            p2--;
        }
        
        if(cry) {
            ans.push_back('1');
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

/* Concise Code */
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1;
        
        string ans = "";
        int sum = 0;
        
        while(i >= 0 || j >= 0 || sum == 1) {
            sum += i >= 0 ? a[i--] - '0' : 0;
            sum += j >= 0 ? b[j--] - '0' : 0;
            
            ans = char(sum%2 + '0') + ans;
            sum = sum/2;
        }
        
        return ans;
    }
};