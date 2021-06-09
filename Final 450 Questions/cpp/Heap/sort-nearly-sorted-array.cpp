/*
  Given a nearly sorted array, then sort the complete array in ascending order 
  OR
  Given k sorted array, sort the complete array.
  k sorted array means, the value which should be present at index i in sorted array will be present between (i-k) to (i+k) index.

  eg:
    arr[] = {6, 5, 3, 2, 8, 10, 9} , k = 3
    so the value at index 0 will be availabe between |0-k| to |0+k| 
    0-k will result into 0 because index cannot be negative
    0+k will result into k
    so tha range become 0 to 3 and we can see than 2 is present at 3rd place from 0th index
    similarly all other elements are placed.
*/

#include <bits/stdc++.h>
using namespace std;

/* 
  Brute Force approach is to directly sort the array
  Time Complexity: O(nlog(n)), Space Complextiy: O(n)
*/

vector<int> sortKSortedArray(vector<int> arr, int k) {
  int n = arr.size();

  /* Approach is => We know that the value which should be present at ith index is currently present either k distance to its left or kth distance to its right
  So to sort the array in ascending order we would need to find the minimum element from index 0-k to 0+k index to get the value which should be present at 0th index
  Similarly, for 1st index we would need to find the minimum element from (1-k)th index to (1+k)th index excluding the value which we choose for the 0th position...

  So, to perform the above operation the best data structure we can use is heap.
  So, till the size of heap is less than or equal to k, push all the elements
  Then after traversing from k+1 element, pop the top element (this will be the value of the 0th index) and push the k+1 element

  Time Complexity: O((k)log(n))
  Space Complexity: O(1) if you change the original array
   */

  priority_queue<int, vector<int>, greater<int>> minHeap;
  int j = 0;
  for(int i=0; i<n; i++) {
    minHeap.push(arr[i]);
    if(minHeap.size() == (k+1)) {
      arr[j++] = minHeap.top();
      minHeap.pop();
    }
  }

  while(!minHeap.empty()) {
    arr[j++] = minHeap.top();
    minHeap.pop();
  }

  return arr;
}

int main() {
  int n, k; cin >> n >> k;

  vector<int> arr(n);
  for(int i=0; i<n; i++) {
    int val; cin >> val;
    arr[i] = val;
  }

  vector<int> ans(sortKSortedArray(arr, k));
  for(int no : ans) cout << no << " ";
}