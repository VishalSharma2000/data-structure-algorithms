/*
When we have to solve any question of array with recursion we should always start with the last index

here we are comparing k with the last index value of array, if its same then return true otherwise 
again call the function with one value less....

if size of n becomes 0 then value is not presetn
*/

bool present(int *arr, int n, int k) {
  if(n == 0) return false;
  if(arr[n-1] == k) return true;

  return present(arr, n-1, k);
}

int main() {
  int n, k; cin >> n >> k;

  int arr[n];
  for(int i=0; i<n; i++) cin >> arr[i];

  cout << present(arr, n, k) << endl;
}