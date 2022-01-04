/* Given the number n and some restrictions about which vowel should come after which vowels we have to find the 
number of permutation of words possible */

/* Basically, here we have represented the problem in the form of graph. Where it represent on which node (char) we can go from current
character */

/* 
    Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
    Each vowel 'a' may only be followed by an 'e'.
    Each vowel 'e' may only be followed by an 'a' or an 'i'.
    Each vowel 'i' may not be followed by another 'i'.
    Each vowel 'o' may only be followed by an 'i' or a 'u'.
    Each vowel 'u' may only be followed by an 'a'.

    The above is represented as below
    start   =>  a / e / i / o / u              # start denotes 1st character of string which can be any vowel
    a       =>  e
    e       =>  a / i
    i       =>  a / e / o / u
    o       =>  i / u
    u       =>  a

    So, we can start with any character and then can choose the characters one by one and if we can get the string of length
    n then we have obtained 1 string.

    suppose n = 5
    so we started with s = a, and the required length is n-1 (4)(since we have occupied one position)
    then from a we can only e so we will go to e and now the required length is n-2 (3) (now we have occupied one more space)
    from e we can either go to a or i. So, we can iterate here and go to these characters one by one
    similarly we can go to other strings by decreasing the required length

    and when we get the value of required length as 0 then we can say that we have obtained a string of length n and hence here 
    we will return 1 to denote that we can obtained the length otherwise we will return 0.

    Now there can be the case when we may not obtain the string of length n. The case is suppose it's given that a particular vowel
    say e should be at the end. Then we can again call the above discussed logic but we should search for string of length n-1 bcoz 
    last character will be taken by e
*/

/* Brute Force Recursive approach of above logic */
class Solution {
public:
    /* the below is basically a kind of adj list graph. Usually we take as input from user but since
    this is not give by user we have making it like this */
    unordered_map<char, vector<char>> mappings = {{'s', {'a', 'e', 'i', 'o', 'u'}}, 
                                                        {'a', {'e'}},
                                                        {'e', {'a', 'i'}},
                                                        {'i', {'a', 'e', 'o', 'u'}},
                                                        {'o', {'i', 'u'}},
                                                        {'u', {'a'}}
                                                       };
    const int MOD = 1000000007;
    
    int solve(char currChar, int remLen) {
        /* We got the string of lenght n */
        if(remLen == 0) return 1;
        
        int ans = 0;
        vector<char> allNextValidChars = mappings[currChar];
        /* Traversing over all valid characters and adding them considering them one by one */
        for(char nextChar : allNextValidChars) {
            ans = (ans + solve(nextChar, remLen-1)) % MOD;
        }
        
        return ans;
    }
    
    int countVowelPermutation(int n) {
        return solve('s', n);
    }
};

/* Another better way of writing the above code */
/*
We will map the vowels to numbers:
    a:0
    e:1
    i:2
    o:3
    u:4

So the directed graph becomes,
    a:{e}       or      0->{1}      
    e:{a,i}     or      1->{0,2}
    i:{a,e,o,u} or      2->{0,1,3,4}
    o:{i,u}     or      3->{2,4}
    u:{a}       or      4->{0}    
    
    
*/
class Solution {
public:
    const int mod = 1e9+7;
    int dp[5][20002];

    int add(int a,int b) {
        return (a%mod + b%mod)%mod;
    }

//     Initialize the graph
    vector<vector<int>> graph = { {1}, {0,2}, {0,1,3,4}, {2,4}, {0}};
    
    int dfs(int src,int n)
    {
        if(n==1) return 1;
        
        if(dp[src][n] != -1)
            return dp[src][n];
        
        int res=0;
        for(auto child:graph[src])
            res = add(res, dfs(child,n-1));
        
        return dp[src][n] = res;
    }
    
    int countVowelPermutation(int n) 
    {
        memset(dp,-1,sizeof(dp));
        
        int ans = 0;
        
        for(int i=0;i<5;i++)
            ans = add(ans, dfs(i,n));
        
        return ans;
    }
};

/* Memoized Version - Top Down Approach */

/* Bottom Up approach - Iterative Appraoch */