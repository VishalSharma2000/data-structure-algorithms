#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target) {
  int n = arr.size();
  int start = 0, end = n-1;

  while(start <= end) {
    int mid = start + (end - start)/2;
    /* Don't use mid = (start + end) /2 bcoz it may lead to overflow then start and end both are higher values. */

    if(arr[mid] == target) {
      return mid;
    } else if(arr[mid] > target) {
      end = mid-1;
    } else {
      start = mid+1;
    }
  }

  return -1;
}

/* TC: O(Log2(N)), SC: O(1) */
int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for(int &val : arr) cin >> val;

  int target; cin >> target;

  cout << binarySearch(arr, target) << endl;
}