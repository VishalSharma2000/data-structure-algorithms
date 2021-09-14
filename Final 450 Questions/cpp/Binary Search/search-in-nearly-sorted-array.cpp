/* Problem Stmt: Given an array of nearly sorted elements, find the target element in this set of elements. Nearly sorted means the value at position i in complete sorted array can be at position i+1 or i-1 or i. */

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int n, int target) {
  int start = 0, end = n-1;

  while(start <= end) {
    int mid = start + (end - start)/2;

    if(arr[mid] == target) return mid;
    if(mid-1 >= start && arr[mid-1] == target) return mid-1;
    if(mid+1 <= end && arr[mid+1] == target) return mid+1;

    if(target > arr[mid]) start = mid+2;
    else if(target < arr[mid]) end = mid-2;
  }

  return -1; // not found
}

int main() {
  int n, target;
  cin >> n >> target;

  vector<int> arr(n);
  for(int &val : arr) cin >> val;

  cout << binarySearch(arr, n, target) << endl;
}