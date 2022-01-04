/* Given an sorted array and the target element return the element which has minimum absolute difference from the target element */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minDifferenceVal(vector<int> &arr, int n, int target) {
  int start = 0, end = n-1;

  while(start <= end) {
    int mid = start + (end-start)/2;

    if(arr[mid] == target) return arr[mid];
    if(target > arr[mid]) start = mid+1;
    else end=mid-1;
  }

  /* When the binary search loop ends, if element is not found then 
  low points to the number which is just greater than target and high points to the number which is just smaller than the target */

  int diff1 = INT_MAX, diff2 = INT_MAX; // diff1 = abs(target - arr[high]), diff2 = abs(arr[low] - target)
  if(start != n) {
    // low == n when target is greater than all elements 
    diff2 = abs(arr[start] - target);
  }

  if(end != -1) {
    // high == -1 when target is the less than all elements
    diff1 = abs(target - arr[end]);
  }

  return diff2 < diff1 ? arr[start] : arr[end];
}

int main() {
  int n, target;
  cin >> n >> target;

  vector<int> arr(n);
  for(int &val : arr) cin >> val;

  cout << minDifferenceVal(arr, arr.size(), target) << endl;
}