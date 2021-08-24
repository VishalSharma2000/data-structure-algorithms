#include <bits/stdc++.h>
using namespace std;

/* To do so, permute takes the index of the current element currentindex(i) as one of the arguments. Then, it swaps the current element with every other element in the array, lying towards its right, so as to generate a new ordering of the array elements. After the swapping has been done, it makes another call to permute but this time with the index of the next element in the array. While returning back, we reverse the swapping done in the current function call.

Thus, when we reach the end of the array, a new ordering of the array's elements is generated. */

/* TC: O(N! => to find all permutation), O(N! *N) => to print all permutation */
void findAllPermutations(vector<int> &nums, int l, int h, vector<vector<int> > &ans) {
    if(l == h) 
        ans.push_back(nums);
    else {
        for(int i=l; i<=h; i++) {
            swap(nums[l], nums[i]);
            
            findAllPermutations(nums, l+1, h, ans);
            
            swap(nums[l], nums[i]);
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    int n = nums.size();
    
    vector<vector<int> > ans;
    if(n == 0) return ans;
    findAllPermutations(nums, 0, n-1, ans);
    
    return ans;
}

/*
    Idea of finding permutation is we keep every character at every position 
*/


void util(string s, int pos, bool visited[], string &nextPer) {
    if(nextPer.length() == s.length()) {
        cout << nextPer << endl;
    } else {
        for(int i=0; i<s.length(); i++) {
            if(!visited[i]) {
                visited[i] = true;
                nextPer.push_back(s[i]);

                util(s, pos+1, visited, nextPer);

                visited[i] = false;
                nextPer.pop_back();
            }
        }
    }
}

void solve(string s) {
    int len = s.length();

    bool visited[len]; for(int i=0; i<len; i++) visited[i] = false;
    string nextPer;

    util(s, 0, visited, nextPer);
}

int main() {    
    string s = "AB";
    solve(s);
}