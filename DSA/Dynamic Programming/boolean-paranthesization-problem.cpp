/* Given a expression consisting of T, F, |, & and ^, find the number of ways this expression can be evaulated to true */
/* https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/ */

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

/* TC: O(N^3) */
int findWays(string s, int i, int j, bool isTrue) {
    // base condition
    if(i == j) {
        if(isTrue) 
            return s[i] == 'T';
        else 
            return s[i] == 'F';
    }
    
    // memoization
    string key = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
    if(mp.find(key) != mp.end()) {
      return mp[key];
    }

    int ans = 0;
    for(int k=i+1; k<=j-1; k+=2) {
        int lt = findWays(s, i, k-1, true);
        int lf = findWays(s, i, k-1, false);
        int rt = findWays(s, k+1, j, true);
        int rf = findWays(s, k+1, j, false);
        
        if(s[k] == '^') {
            if(isTrue) {
                ans += lt * rf + lf * rt;
            } else {
                ans += lt * rt + lf * rf;
            }
        } else if(s[k] == '&') {
            if(isTrue) {
                ans += lt * rt;
            } else {
                ans += lt * rf + lf * rt + lf * rf;
            }
        } else if(s[k] == '|') {
            if(isTrue) {
                ans += lt * rf + lf * rt + lt * rt;
            } else {
                ans += lf * rf;
            }
        }
    }
    
    return mp[key] = ans;
}

int main() {
    string s = "T|T&F^T";
    
    int ways = findWays(s, 0, s.length()-1, true);
    cout << ways << endl;
}