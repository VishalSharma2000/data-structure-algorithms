/* Given a 2d matrix with row wise and column wise sorted, print all the elements of the array in sorted order */

#include <bits/stdc++.h>
using namespace std;

/* Young Tableau Method
Young Tableau is basically a 2d matrix when the elements are row-wise and column-wise sorted
So, at each point we remove the minimum value of the matrix (which is at index (0, 0) ) and replace it with INFINITY then youngify the complete matrix to maintain the property of the matrix. 

In youngify step we find the element which can be shifted to the infinity position till infinity is reached at the right bottom of the array, hence maintaining the property of the array 

Extract Min takes O(max(N, M)) time and we need to do it N*M time 
so total time completexity will be O(N*M*max(N*M)) OR O(N^3) */
void youngify(vector<vector<int>> &arr, int i, int j) {
  int n = arr.size(), m = arr[0].size();
  
  int down = (i+1 < n) ? arr[i+1][j] : INT_MAX;
  int right = (j+1 < m) ? arr[i][j+1] : INT_MAX;

  if(down == INT_MAX && right == INT_MAX) return;

  if(down < right) {
    arr[i][j] = down;
    arr[i+1][j] = INT_MAX;
    youngify(arr, i+1, j);
  } else {
    arr[i][j] = right;
    arr[i][j+1] = INT_MAX;
    youngify(arr, i, j+1);
  }
}

void printSortedOrder(vector<vector<int>> &arr,int n, int m) {
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      int val = arr[0][0];
      arr[0][0] = INT_MAX;
      cout << val << " ";
      youngify(arr, 0, 0);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> arr(n, vector<int>(m));
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      int val;
      cin >> val;
      arr[i][j] = val;
    }
  }

  printSortedOrder(arr, n, m);
}

/* We can solve by the method - merge k sorted array (here k is number of rows) using priority_queue */