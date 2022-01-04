/* 
Question: https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/

For each value at (i, j) we need to find the maximum value from (i+1, j+1) to (N-1, N-1). So, to do that we do pre processing and find the maximum value and find the maximum value from (i, j) to (N-1, N-1) for all (i, j)
So,
This question basically drills down to finding the maximum value from position (i, j) to (N-1, N-1)

So, the brute force approach to do that was to first suffix maximum array for each row 
and then in the same array find the suffix maximum array from each column 

After above two operations we will get the maximum value from (i,j) to (N-1, N-1)

Better way:
A better way to do it is only find the suffix maximum array of last row and last column 
and traverse array from (N-2, N-2) and the max value amoung mat[i][j], maxHere[i+1][j], maxHere[i][j+1]
will give us the max value from (i, j) to (N-1, N-1)
*/
#include <bits/stdc++.h>
using namespace std;

#define N 5

int findMaxValue(int mat[][N]) {
    int maxHere[N][N];
    
    maxHere[N-1][N-1] = mat[N-1][N-1];
    
    // process last row
    for(int i=N-2; i>=0; i--) {
        maxHere[N-1][i] = max(mat[N-1][i], maxHere[N-1][i+1]);
    }
    
    // process last column
    for(int i=N-2; i>=0; i--) {
        maxHere[i][N-1] = max(maxHere[i+1][N-1], mat[i][N-1]);
    }
    
    int maxValue = INT_MIN;
    for(int i=N-2; i>=0; i--) {
        for(int j=N-2; j>=0; j--) {
            maxValue = max(maxValue, maxHere[i+1][j+1] - mat[i][j]);
            
            maxHere[i][j] = max({ mat[i][j], maxHere[i+1][j], maxHere[i][j+1] });
        }
    }
    
    return maxValue;
}

int main() {
    int mat[N][N] = {
                      { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 }
                    };
    cout << "Maximum Value is " << findMaxValue(mat); 
}