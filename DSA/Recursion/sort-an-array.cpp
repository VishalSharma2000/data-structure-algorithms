/* Given an array, sort the array using recursion */
/* sortArray functino will be called n times because size of array is n and for each element we will call arrangeArray which will cost O(N) 

T(N) = T(N-1) + O(N)
*/
#include <iostream>
using namespace std;

/* Hypo => given an array of size n such that first n-1 elements are sorted then this function will put the last element into it's correct position */
void arrangeArray(int arr[], int n) {
  if(n < 2) return;

  if(arr[n-1] < arr[n-2]) {
    swap(arr[n-1], arr[n-2]);

    arrangeArray(arr, n-1);
  }
}

/* Since, we don't have any decision or choice to make, we will go with IBH method.
So, Hypothesis => if I give an array to a function that that function will sort that array....
Here we are keeping the last value of the array with us  and recursively calling the sortArray function will smaller input so that 
it gets sorted, after that we can placing that reserved value into it's correct position */
void sortArray(int arr[], int n) {
  if(n < 2) return;

  // we are calling recursively for smaller input
  sortArray(arr, n-1); // no. of calls => O(N), each call cost => O(N) for arrangeArray

  // put the last value of the array into it's correct position
  arrangeArray(arr, n); // cost O(N)
}

int main() {
  int n;
  cin >> n;

  int arr[n];
  for(int i=0; i<n; i++) cin >> arr[i];

  sortArray(arr, n);

  for(int i=0; i<n; i++) cout << arr[i] << " ";
}