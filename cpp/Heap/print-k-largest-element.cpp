/*
  Given the array print the k largest elements of the array
*/

#include <bits/stdc++.h>
using namespace std;

/* Brute Force approach to solve the problem is to sort the array and then print the last k elements
  Time Complexity => O(nlog(n)) used for sorting
  Space Complexity => O(n) used in sorting
 */
void printKLargestUsingSort(vector<int> &arr, int k) {
  int n = arr.size();

  sort(arr.begin(), arr.end());

  for(int i=0; i<k; i++) {
    cout << arr[n-1-i] << " ";
  }
}

/* 
  Since, we have to find the largest k elements so there is no need to sort the full array...bcoz in sorting we are also doing an extra work to sort all n-k elements. So, here we can make use of minheap to store the largest k elements and not to worry about the other n-k elements
*/

void printKLargestUsingHeap(vector<int> &arr, int k) {
  int n = arr.size();

  priority_queue<int, vector<int>, greater<int>> minHeap;
  /* If you are wondering what is it => priority_queue<data_type, container, constructor>. We can make our own constructor if needed */

  /* Push until the size of the heap is less than k, otherwise if push only if the element is greater then minHeap.top() */
  for(int i=0; i<n; i++) {
    /* Understandable Code */

    if(minHeap.size() < k) minHeap.push(arr[i]);
    else if(arr[i] > minHeap.top()) {
      minHeap.pop();
      minHeap.push(arr[i]);
    }

    /* More concise code */
    /* minHeap.push(arr[i]);
    if(minHeap.size() > k) 
      minHeap.pop(); */
  }

  /* Copy all the elements into vector, while copying the elements will be sorted into ascending order */
  vector<int> ans(minHeap.size());
  for(int i=0; i<ans.size(); i++) {
    ans[i] = minHeap.top();
    minHeap.pop();
  }

  for(int i=ans.size()-1; i>=0; i--) cout << ans[i] << " ";

  return;
}

int main() {
  int n, k; cin >> n >> k;

  vector<int> arr(n);
  for(int i=0; i<n; i++) {
    int val; cin >> val;
    arr[i] = val;
  }

  printKLargestUsingSort(arr, k);
  printKLargestUsingHeap(arr, k);
}