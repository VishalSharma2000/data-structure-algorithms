bool isPalindrome(string s) {
    string s1 = s;
    reverse(s1.begin(), s1.end());
    
    return s1 == s;
}

int memo[100][100];

int getPartition(string s, int i, int j) {
    if(i > j) 
        return 0; // empty string, already palindrome hence no parition required
    
    if(memo[i][j] != -1) return memo[i][j];

    if(isPalindrome(s.substr(i, j-i+1))) 
        return memo[i][j] = 0; // if already palindrome then no partition required
    
    int ans = j - i + 1; // we can do n (size of string) paritition such that each parition has one character which will be palindromic
    for(int k=i; k<j; k++) {
        int tempAns = 1 + getPartition(s, i, k) + getPartition(s, k+1, j);
        
        ans = min(tempAns, ans);
    }
    
    return memo[i][j] = ans;
}

/* Optimization */

int getPartition(string s, int i, int j) {
    if(i > j) 
        return 0; // empty string, already palindrome hence no parition required
    
    if(memo[i][j] != -1) return memo[i][j];

    if(isPalindrome(s.substr(i, j-i+1))) 
        return memo[i][j] = 0; // if already palindrome then no partition required
    
    int ans = j - i + 1; // we can do n (size of string) paritition such that each parition has one character which will be palindromic
    for(int k=i; k<j; k++) {
        int left = isPalindrome(s, i, k) ? 0 : getPartition(s, i, k);
        int right = isPalindrome(s, k+1, j) ? 0 : getPartition(s, k+1, j);
        int tempAns = 1 + left + right;
        
        ans = min(tempAns, ans);
    }
    
    return memo[i][j] = ans;
}

int main() {
    string s = "vishal";
    int n = s.length();
    
    memset(memo, -1, sizeof memo);

    int partition = getPartition(s, 0, n-1);
    cout << partition << endl;
}