/*  */

#include <bits/stdc++.h>
using namespace std;

char binarySearchNext(string s, int n, char target) {
  int start = 0, end = n-1;
  int res = -1;

  while(start <= end) {
    int mid = start + (end - start)/2;

    if(s[mid] <= target) {
      start = mid+1;
    } else if(s[mid] > target) {
      res = mid;
      end = mid-1;
    }
  }

  // cout << res << endl;
  if(res != -1) return s[res];
  return res;
}

int main() {
  int n;
  char target;
  cin >> n >> target;

  string s;
  cin >> s;
  // cout << n << " " << target << " " << s << endl;
  cout << binarySearchNext(s, n, target) << endl;
}