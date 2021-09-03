#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n) {
  /* We compare adjacent elements of the array and swap if first element is greater than second element. We continue doing this for all the elements from index 0 to n-1-i for n-1 times. Because we just have to place n-1 elements to their correct position. Last element will automatically get it's correct position. So, basically at the end of each pass we get the greatest number at the end of the array */
  for(int i=0; i<n-1; i++) {
    for(int j=0; j<n-1-i; j++) {
      /* Note the terminating condition here...it's n-1-i, since we have recived i number of greater elements at the end of the array there is no need to traverse again for them */
      if(arr[j] > arr[j+1]) 
        swap(arr[j], arr[j+1]);
    }
  }
}

/* As the name implies we select the number and place it at it's correct position. So, idea is to find n-1 smallest element of the array and place them to it's correct position. So, i is the iterator for doing n-1 times, and each time we are tarversing from i+1 to n to find the next smallest number. After finding the smallest number we just replace it will the number at ith position */
void selectionSort(int arr[], int n) {
  for(int i=0; i<n-1; i++) {
    int minValIndex = i; // initialize minValIndex with current value, bcoz there can the case that current value is the next smallest number
    for(int j=i+1; j<n; j++) {
      /* Find the smallest number from the rest of the array */
      if(arr[minValIndex] > arr[j])
        minValIndex = j;
    }

    // swap the smallest number with the number at ith position
    swap(arr[i], arr[minValIndex]);
  }
}

/* Here we insert the current value at it's correct position for the current sorted array. 
Note that in bubble sort, at the end of each iteration we get a sorted array from [n-1-i, n-1] and in selection sort we get a sorted array from [0, i]. Similarly, here also we get the sorted array from [0, i] at the end of each iteration. So here, the idea is to keep the current value as key and iterator for i-1 to 0 till we get the numbers greater than the current value. For those numbers which are greater we will store them at one index higher. When the condition fails, then that position will be the correct position of that number for the current sorted array */
void insertionSort(int arr[], int n) {
  for(int i=1; i<n; i++) {
    int key = arr[i];
    int j=i-1;

    while(j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];
      j--;
    }

    arr[j+1] = key;
  }
}

int main() {
  int n;
  n = 7;

  int arr[n] = {9, 4, 3, 2, 7, 2, 1};
  // bubbleSort(arr, n);
  // selectionSort(arr, n);
  insertionSort(arr, n);

  for(int i=0; i<n; i++) cout << arr[i] << " ";
}