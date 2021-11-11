/* Question: https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/ */
/* Brute force approach is to just convert row to columns i.e. write first row as last column, second row as second last column and so on (if extra space is allowed) , But extra space is not allowed here so we try to see some observation */

/* 
The idea is for each square cycle, swap the elements involved with the corresponding cell in the matrix in clockwise direction or anti-clockwise direction (as per the question) 

if anti-clockwise =>  from top to left, left to bottom, bottom to right and from right to top one at a time using nothing but a temporary variable to achieve this.
if clockwise => from top to right, right to bottom, bottom to left and left to top

For all cyclic square(outer rows and columns) we can see the pattern amoung the indices of rotated matrix and unrotated matrix 
to rotate
(i, j) -> (j, n-1-i) -> (n-1-i, n-1-j) -> (n-1-j, i) -> (i, j) */

/* If a matrix is of size N x N then it will be N/2 cyclic square */ 
#include <bits/stdc++.h>
using namespace std;

#define N 4


void printMatrix(int arr[][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << arr[i][j] << " ";
        }
        
        cout << endl;
    }
    cout << endl;
}

void rotate90Clockwise(int arr[][N]) {
// my first approach
//     int size = N;
    
//     int sr = 0, sc = 0;
//     while(size >= 2) {
//         int i = sr, j = sc;
        
//         for(int t=0; t<size-1; t++) {
//             int temp = arr[N-1-j][i];
//             arr[N-1-j][i] = arr[N-1-i][N-1-j];        
//             arr[N-1-i][N-1-j] = arr[j][N-1-i];
//             arr[j][N-1-i] = arr[i][j];
//             arr[i][j] = temp;
            
//             i++;
            
//             printMatrix(arr);
//         }

//         sr++, sc++;
//         size -= 2;
//     }
    
    for(int i=0; i<N/2; i++) { // for all cyclic square
        for(int j=i; j<N-1-i; j++) { // as per observation 
            // store bottom value
            int temp = arr[N-1-j][i];
            
            // bottomleft to topleft
            arr[N-1-j][i] = arr[N-1-i][N-1-j];        
            
            // topleft to topright
            arr[N-1-i][N-1-j] = arr[j][N-1-i];
            
            // topright to bottomright
            arr[j][N-1-i] = arr[i][j];
            
            // bottomright to bottomleft
            arr[i][j] = temp;
        }
    }
}


int main()
{
    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate90Clockwise(arr);
    printMatrix(arr);
    return 0;
}