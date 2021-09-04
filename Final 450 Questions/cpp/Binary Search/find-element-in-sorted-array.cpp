#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for(int &val : arr) cin >> val;

  int k;
  cin >> k;

  int foundAt = -1;
  int start = 0, end = n-1;
  while(start <= end) {
    int mid = (start + end) / 2; // or start + (end - start) /2;

    if(arr[mid] == k) {
      foundAt = mid;
      break;
    } else if(arr[mid] > k) {
      end = mid-1;
    } else {
      start = mid+1;
    }
  }

  if(foundAt == -1) cout << "Not Found" << endl;
  else cout << foundAt << endl;
}