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

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    
    /* 
        If we will create a 2d array for storing the overlapping problems, then
        the value at index 0,0 i.e dp[0][0] will never be used. 
        
        But if we will use 1d array (as used here) then dp[0] value will be used, hence
        the value by which it is initialized will matter
    */
    int dp[amount+1];
    for(int i=1; i<amount+1; i++) dp[i] = INT_MAX-1;
    dp[0] = 0;
    
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
        }
    }
    
    if(dp[amount] == INT_MAX-1) return -1;
    return dp[amount];
}

int main() {
    int n, val, amount; 
    
    cin >> n;
    vector<int> coins(n);

    for(int i=0; i<n && cin >> val; i++) coins[i] = val;

    cin >> amount;

    cout << "Minimum Number of coins needed to make the change = " << coinChange(coins, amount) << endl;
}
