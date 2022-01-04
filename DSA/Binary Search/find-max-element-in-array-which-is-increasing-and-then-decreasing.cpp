/* 
arr elements will be always in the form

    /\
  /   \
/      \

*/

#include <iostream>
using namespace std;

int findMaximum(int arr[], int n) {
	int low = 0, high = n-1;

	while(low <= high) {
		// if only one element is present
		if(low == high) return arr[low];

		if(high == low+1) {
			// if search space is of size 2
			if(arr[low] > arr[high]) return arr[low];
			else return arr[high];
		}

		int mid = low + (high - low)/2;
		// if arr[mid] is greater than it's adjacent elements then it is the largest
		if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return arr[mid];
		// if increasing order is present then the max value will be in right side
		else if(arr[mid] > arr[mid-1] && arr[mid] < arr[mid+1]) low = mid + 1;
		// else left side
		else high = mid - 1;
	}

	return -1;
}

int main() {
	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++) cin >> arr[i];

	cout << findMaximum(arr, n) << endl;
}