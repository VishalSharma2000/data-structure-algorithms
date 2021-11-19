/* Given a string of length n, find the longest palindromic substring */

/* Brute Force Approach - Find all the possible substring and check if the substring is palindromic or not. */
/* TC: O(N^3), SC: O(1) */
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        int maxLength = 1, start = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                // i=> startPointer, j=> endPointer
                int len = j-i+1;
                
                // checking palindrome
                bool palindrome = true;
                for(int k=0; k<len/2; k++) {
                    if(s[i+k] != s[j-k]) {
                        palindrome = false;
                        break;
                    }
                }
                
                if(palindrome && (j-i+1) > maxLength) {
                    maxLength = j-i+1;
                    start = i;
                }
            }
        }
        
        return s.substr(start, maxLength);
    }
};

/* Dynamic Programming approach - It's not purely overlapping subproblem kind off approach. A normal observation that
substring of a string from i to j is palindromic if 
P(i, j) = P(i+1, j-1) && (s[i] == s[j]) 

base case
P(i, i) = true
P(i, i+1) = s[i] == s[i+1]

so starting from substring of length 1 and 2, find the palindromic length for all the substrings of length 3 to n
*/
/* TC: O(N^2), SC:O(N^2) */
// A C++ dynamic programming
// solution for longest palindrome

#include <bits/stdc++.h>
using namespace std;

int longestPalSubstr(string str) {
	int n = str.size();

	bool table[n][n];
	memset(table, 0, sizeof(table));

	int maxLength = 1;

	for (int i = 0; i < n; ++i)
		table[i][i] = true;

	// check for sub-string of length 2.
	int start = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (str[i] == str[i + 1]) {
			table[i][i + 1] = true;
			start = i;
			maxLength = 2;
		}
	}

	for (int k = 3; k <= n; ++k) {
		// Fix the starting index
		for (int i = 0; i < n - k + 1; ++i) {
			// Get the ending index of substring from
			// starting index i and length k
			int j = i + k - 1;

			// checking for sub-string from ith index to
			// jth index iff str[i+1] to str[j-1] is a
			// palindrome
			if (table[i + 1][j - 1] && str[i] == str[j]) {
				table[i][j] = true;

				if (k > maxLength) {
					start = i;
					maxLength = k;
				}
			}
		}
	}

	return maxLength;
}

// Driver Code
int main()
{
	string str = "forgeeksskeegfor";
	cout	<< longestPalSubstr(str);
	return 0;
}


/* TC: O(N^2), SC: O(1) */
class Solution {
public:
    string longestPalindrome(string s) {
        string str = "";
        int start = 0;
        int maxLength = 1;

        for(int i=0; i<s.length(); i++) {
            int len1 = expandFromMiddle(s, i, i); // odd length palindrome check
            int len2 = expandFromMiddle(s, i, i+1); // even length palindrme check
            
            int start1 = i - ((len1-1)/2);
            int start2 = i - ((len2-2) / 2);
            
            if(len1 > maxLength) {
                start = start1;
                maxLength = len1;
            }
            if(len2 > maxLength) {
                start = start2;
                maxLength = len2;
            }
        }
        
        return s.substr(start, maxLength);
    }
    
    int expandFromMiddle(string s, int left, int right) {
        if(s.length() == 0 || left > right) return 0;
        
        while(left >=0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        
        left++, right--;

        return (right-left) + 1;
    }
};