#include <bits/stdc++.h>
using namespace std;

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