#include <bits/stdc++.h>
using namespace std;

bool subsetSumPossible(int arr[], int n, int sum) {
  bool DP[n+1][sum+1];

  /*
    Row => size of the array
    Column => required Sum

    Initialization:
      1st Column will be all true: bcoz to get a sum of zero we can have an empty set...so if are not provided with any value
      in the set then also we can have a sum equal zero.
      1st Row (i = 1 to sum) will be false: bcoz if we are not provided with any number in the array then we can't have any 
      sum more than 0
  */

    for(int i=0; i<n+1; i++) DP[i][0] = 1;
    for(int i=1; i<sum+1; i++) DP[0][i] = 0;

    for(int n1=1; n1<n+1; n1++) {
      for(int sum1=1; sum1<sum+1; sum1++) {
        if(arr[n1-1] <= sum1) {
          DP[n1][sum1] = DP[n1-1][sum - sum1] || DP[n1-1][sum1];
        } else {
          DP[n1][sum1] = DP[n1-1][sum1];
        }

        /*
          Another way of writing

          if(DP[n1-1][sum1]) {
            // if the required sum i.e. sum1 is already obtained from n1-1 set of numbers then no need to check further
            DP[n1][sum1] = true;
          } else if(arr[n1-1] <= sum1) {
            // if the number at index n1-1 is less than the required sum, then include it and check if already including the remaining sum can 
            // obtained from remaining n1-1 nos of the array
            DP[n1][sum1] = DP[n1-1][sum - sum1];
          } else {
            // if the current number i.e. arr[n1-1] is itself more than the required sum then achieving given sum is not possible.
            DP[n1][sum1] = DP[n1 - 1][sum1];
          }
        */
      }
    }

    return DP[n][sum];
}

int main() {
  int n;cin >>n;

  int arr[n], sum;
  for(int i=0; i<n; i++) cin >> arr[i];

  cin >> sum;

  cout << subsetSumPossible(arr, n, sum) << endl;
}