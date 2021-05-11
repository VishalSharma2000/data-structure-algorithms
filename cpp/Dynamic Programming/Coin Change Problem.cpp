#include <bits/stdc++.h>
using namespace std;

int mem[10000][10000];

int coinChangeBruteForce(vector<int> &coins, int n, int amount) {
  if(n == 0 || amount < 0) return 0;
  /* If I don't have any coins with me, then I will not be able to make any change for any amount. So, total number of ways to make change for given
  amount with given coins (here 0) will be 0 
  OR
  If the amount is invalide i.e. less than zero, then no way to get the change.
  */

  if(amount == 0) return 1;
  /* If the given amount is zero, then it will not matter if we have coins or not...to make change, we can return empty set or empty hand.
  Hence total possbile way will be 1 */

  return coinChangeBruteForce(coins, n-1, amount) + coinChangeBruteForce(coins, n, amount - coins[n-1]);
  /* So, in the first call we are calling the recursion function without including the denomination element at n-1 position, hence the amount remain the same
  In the second call, we are considering the denomination element at pos n-1, hence including it. Note we can also take this element in future that is why the size of the array remains the same*/
}

int coinChangeBruteForceMemoized(vector<int> &coins, int n, int amount) {
  if(amount < 0) return 0;
  if(n == 0) return mem[n][amount] = 0;
  if(amount == 0) return mem[n][amount] = 1;

  if(mem[n][amount] != -1) return mem[n][amount];

  return mem[n][amount] = coinChangeBruteForce(coins, n-1, amount) + coinChangeBruteForce(coins, n, amount - coins[n-1]);
}

int coinChange(vector<int>& coins, int amount) {
  int n = coins.size();

  int dp[n+1][amount+1]; // for storing the repetative calls

  for(int i=0; i<n+1; i++) dp[i][0] = 1;
  for(int i=1; i<amount+1; i++) dp[0][i] = 0;

  for(int i=1; i<n+1; i++) 
    for(int j=1; j<amount+1; j++) {
      if(coins[i-1] <= j)
        dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
      else 
        dp[i][j] = dp[i-1][j];
    }
  
  return dp[n][amount];
}

int main() {
    int n, val, amount; 
    
    cin >> n;
    vector<int> coins(n);

    for(int i=0; i<n && cin >> val; i++) coins[i] = val;

    cin >> amount;

    // Brute Force Approach
    cout << "Maximum Number of ways to make change for the given amount = " << coinChangeBruteForce(coins, coins.size(), amount) << endl;

    // Memoized Version Call
    for(int i=0; i<n+1; i++) for(int j=0; j<amount+1; j++) mem[i][j] = -1;
    cout << coinChangeBruteForceMemoized(coins, n, amount) << endl;

    // Dp Solution
    cout << coinChange(coins, amount) << endl;
}
