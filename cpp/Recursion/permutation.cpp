void permute(string &str, int l, int r, vector<string> &ans) {
    if(l == r) ans.push_back(str);
    else {
        for(int i=l; i<=r; i++) {
            swap(str[l], str[i]);
            permute(str, l+1, r, ans);
            swap(str[i], str[l]);
        }
    }
}

vector<string> permutation(string S) {
    vector<string> ans;
    permute(S, 0, S.length()-1, ans);
    return ans;
}