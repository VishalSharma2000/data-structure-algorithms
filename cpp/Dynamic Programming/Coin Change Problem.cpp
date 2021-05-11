#include <bits/stdc++.h>
using namespace std;

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

int coinChange(vector<int>& coins, int amount) {
  return 0;
}

int main() {
    int n, val, amount; 
    
    cin >> n;
    vector<int> coins(n);

    for(int i=0; i<n && cin >> val; i++) coins[i] = val;

    cin >> amount;

    cout << "Maximum Number of ways to make change for the given amount = " << coinChangeBruteForce(coins, coins.size(), amount) << endl;
}
