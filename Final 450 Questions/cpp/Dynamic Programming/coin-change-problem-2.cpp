/*
    Problem Statement: 
    Give the set of coins and an amount, we have to find the minimum number of coins needed to make the change of the
    given amount

    Comparision with Count Subset Sub Problem:
    The only difference between CSSP and CCP is that in the former we can choose one particular element only once while in the later we can choose
    the elements any number of times. 

    ex: coins[] = [1, 2, 3]
    amount = 5
    So, ans => 2 + 3, 2 coins will be needed to make amount 5
*/
#include <bits/stdc++.h>
using namespace std;

/* Memoization Apporach Start */
class Solution {
public:
    int memo[13][10001];
    
    // will return the minimum number of coins to make the amount
    int helper(vector<int> &coins, int n, int amount) {
        if(amount == 0) return 0;
        if(n == 0) return INT_MAX-1;
        
        if(memo[n][amount] != -1) {
            return memo[n][amount];
        }
        
        if(coins[n-1] <= amount) {
            return memo[n][amount] = 
                min(1 + helper(coins, n, amount - coins[n-1]), helper(coins, n-1, amount));
        } else {
            return memo[n][amount] = helper(coins, n-1, amount);
        }
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        memset(memo, -1, sizeof memo);
        
        int ans = helper(coins, n, amount);
        if(ans == INT_MAX-1) return -1;
        else return ans;
    }
};
/* Memoization Apporach End */

/* Bottom up approach - 2d array solution */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // bottom up approach
        int n = coins.size();
        
        int dp[n+1][amount+1];
        
        // initialization
        for(int i=0; i<n+1; i++) dp[i][0] = 0;
        for(int i=1; i<amount+1; i++) dp[0][i] = INT_MAX-1;
        
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<amount+1; j++) {
                if(coins[i-1] <= j)
                    dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][amount] == INT_MAX-1 ? -1 : dp[n][amount];
    }
};
/* Bottom up approach - 2d array solution */

/* Bottom Up Approach - 1d array solution */
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
  
    int dp[amount+1];
    dp[0] = 0;
    for(int i=1; i<amount+1; i++) dp[i] = INT_MAX-1;
    
    /*
        Here, INF = INT_MAX-1
        Reason for choosing INF = INT_MAX-1, bcoz we will add 1 while counting the 
        number of coins needed to make the value amount...
        Note: INF will not go above INT_MAX-1 bcoz we are always taking minimum value 
        amoung two values we are comparing, so comparision between INT_MAX-1, INT_MAX will
        result into INT_MAX-1
    */
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<amount+1; j++) {
            if(coins[i] <= j) 
                dp[j] = min(1 + dp[j - coins[i]], dp[j]);
            // no need of else part because it will not change anything
            /* else {
              dp[j] = dp[j];
            } */
        }
    }
    
    if(dp[amount] == INT_MAX-1) return -1;
    return dp[amount];
}
/* Bottom Up Approach - 1d array solution */

int main() {
    int n, val, amount; 
    
    cin >> n;
    vector<int> coins(n);

    for(int i=0; i<n && cin >> val; i++) coins[i] = val;

    cin >> amount;

    cout << "Minimum Number of coins needed to make the change = " << coinChange(coins, amount) << endl;
}
