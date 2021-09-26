#include <iostream>
using namespace std;

void arrangeArray(int arr[], int n) {
  if(n < 2) return;

  if(arr[n-1] < arr[n-2]) {
    swap(arr[n-1], arr[n-2]);

    arrangeArray(arr, n-1);
  }
}

void sortArray(int arr[], int n) {
  if(n < 2) return;

  sortArray(arr, n-1);

  arrangeArray(arr, n);
}

int main() {
  int n;
  cin >> n;

  int arr[n];
  for(int i=0; i<n; i++) cin >> arr[i];

  sortArray(arr, n);

  for(int i=0; i<n; i++) cout << arr[i] << " ";
}