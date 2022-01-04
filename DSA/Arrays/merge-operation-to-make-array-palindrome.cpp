/* Given an array of positive nos, find the minimum number of merge operations to make the array palindrome. Merge operation means addition of two adjacent values */

int findMinOps(int arr[], int n) {
  int left = 0, right = n-1;

  int ans = 0;
  while(left <= right) {
    if(arr[left] == arr[right]) {
      left++; right--;
    } else if(arr[left] < arr[right]) {
      left++;
      arr[left] += arr[left-1];

      ans++;
    } else {
      // arr[left] > arr[right]
      right--;
      arr[right] += arr[right+1];

      ans++;
    }
  }

  return ans;
}

int main() {
    int arr[] = {1, 4, 5, 9, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout <<  findMinOps(arr, n) << endl;
    return 0;
}