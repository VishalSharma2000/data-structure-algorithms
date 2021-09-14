/* Given a sorted array and a target element find the floor (largest x <= target) and ceil(smallest x >= target) element in the array */

#include <bits/stdc++.h>
using namespace std;

int binarySearchFloor(vector<int> &arr, int n, int target) {
  int start = 0, end = n-1;
  int res = -1;

  while(start <= end) {
    int mid = start + (end - start)/2;

    if(arr[mid] == target) return mid;
    else if(arr[mid] < target) {
      res = mid;
      start = mid+1;
    } else if(arr[mid] > target) {
      end = mid-1;
    }
  }

  return res;
}

int binarySearchCeil(vector<int> &arr, int n, int target) {
  int start = 0, end = n-1;
  int res = -1;

  while(start <= end) {
    int mid = start + (end - start)/2;

    if(arr[mid] == target) return mid;
    else if(arr[mid] < target) {
      start = mid+1;
    } else if(arr[mid] > target) {
      res = mid;
      end = mid-1;
    }
  }

  return res;
}


int main() {
  int n, target;
  cin >> n >> target;

  vector<int> arr(n);
  for(int &val : arr) cin >> val;

  cout << binarySearchFloor(arr, n, target) << endl;
  cout << binarySearchCeil(arr, n, target) << endl;
}