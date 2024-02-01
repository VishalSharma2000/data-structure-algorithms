### Brute Force Solution
---
Since we want to make a valid paranthesis string of length 2*n, so at each index in [0, 2*n-1] we have two choices

1. To have `'('` at position `i`
2. To have `')'` at position `i`

So, we can try all position strings which can be formed and for each formed string we can check if the string is valid palindrome or not. If it is valid then we will insert into set otherwise we will reject it.
```
class Solution {
public:
    // Utility to check if the string is valid
    bool isValidParanthesis(string s) {
        stack<char> st;
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ')') {
                if(st.empty()) return false;
                if(st.top() != '(') return false;
                
                st.pop();
            } else 
                st.push(s[i]);
        }
        
        return st.empty();
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> allParans;
        string currParans, temp;
        
        for(int i=0; i<2*n; i++) 
            temp.push_back(')');
        
        temp[0] = '(';
        
        for(int i=0; i<pow(2, 2*n); i++) {
            currParans = temp;
            for(int j=0; j<2*n-1; j++) {
                if(i & (1 << j)) {
                    currParans[j] = '(';
                }
            }
            
            if(isValidParanthesis(currParans) && find(allParans.begin(), allParans.end(), currParans) == allParans.end())
                allParans.push_back(currParans);
        }
        
        return allParans;
    }
};
```

---
### Optimized Solution

Now we know that a valid paranthesis string will have 3 open and 3 closing round brackets and in a complete string 

`no. of open bracket should be equal to no. of closing bracket`

```
#include <iostream>
#include <string>
using namespace std;

/* Time Complexity: O(branches ^ depth) = O(2^(2n)) */

void generateBalancedParanthesis(int open, int close, string ou) {
  if(open == 0 && close == 0) {
    cout << ou << endl;
    return;
  }

  if(open > 0) {
    string ou1 = ou + "(";
    generateBalancedParanthesis(open-1, close, ou1);
  }

  if(open < close) {
    string ou1 = ou + ")";
    generateBalancedParanthesis(open, close-1, ou1);
  }
}

int main() {
  int n;
  cin >> n;

  int open = n, close = n;
  string ou = "";

  generateBalancedParanthesis(open, close, ou);
}
```