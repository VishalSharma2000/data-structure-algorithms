/* Given an array of negative and position numbers, we have to bring all the negatives numbers prior to all the position numbers. While doing so we should not affect the relative ordering of the numbers. Try to do it without any extra space or data structure */

#include <bits/stdc++.h>
using namespace std;

/* TC: O(N), SC: O(N) */
void rearrangeNos(int arr[], int n) {
  int temp[n];
  for(int i=0; i<n; i++) temp[i] = arr[i];
  
  int k = 0;
  for(int i=0; i<n; i++) {
    if(temp[i] < 0)
      arr[k++] = temp[i];
  }

  for(int i=0; i<n; i++) {
    if(temp[i] >= 0) 
      arr[k++] = temp[i];
  }
}

/* TC: O(N^2), SC: O(1) */
void rearrangeNos(int arr[], int n) {
  for(int i=1; i<n; i++) {
    int key = arr[i];

    if(key > 0) continue;

    int j = i-1;
    while(j >= 0 && arr[j] > 0) {
      arr[j+1] = arr[j];
      j--;
    }

    arr[j+1] = key;
  }
}

/* Optimize to TC: O(N*LogN) using Merge Sort, SC: O(N) */
void merge(int arr[], int l, int m, int h) {
  int size1 = m-l+1;
  int size2 = h-(m+1)-1;

  int L[size1], R[size2];
  
  for(int i=0; i<size1; i++) {
    L[i] = arr[l + i];
  }
  for(int j=0; j<size2; j++) {
    R[j] = arr[m+1 + j];
  }

  int k = l, i = 0, j = 0;
  while(i <= size1 && L[i] < 0)
    arr[k++] = L[i++];

  while(j <= size2 && R[j] < 0)
    arr[k++] = R[j++];

  while(i <= size1)
    arr[k++] = L[i++];

  while(j <= size2)
    arr[k++] = R[j++];
} 

void rearrangeNosUsingMergeSort(int arr[], int l, int h) {
  if(l < h) {
    int m = l + (h-l)/2;

    rearrangeNosUsingMergeSort(arr, l, m);
    rearrangeNosUsingMergeSort(arr, m+1, h);

    merge(arr, l, m, h);
  }
}

int main() {
  int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
  int n = sizeof(arr) / sizeof(arr[0]);

  rearrangeNos(arr, n);
  for(int i=0; i<n; i++) cout << arr[i] << " ";
}