/* To find the final matrix (i.e. after doing 90 deg anti clockwise rotation) we have two approaches, we can either change the input arr by rotating it 90 deg or we can directly print the matrix in that format */
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

// TC: O(N*N + N*N) = O(reverse + transpose)
void rotate90AntiClockwise(int arr[][N]) {    
   // reverse each row
   for(int i=0; i<N; i++) {
       reverse(arr[i], arr[i] + N);
   }

    // transpose the matrix
    for(int i=0; i<N; i++) {
        for(int j=i; j<N; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

/* If we want to just pring the anti clockwise version, not to rotate the array in anti clockwise direction */ 
void printRotate90DegAntiClockwise(int arr[][N]) {
    for(int col = N-1; col >= 0; col--) {
        for(int row = 0; row < N; row++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    
    printRotate90DegAntiClockwise(arr);
    
    rotate90AntiClockwise(arr);
    printMatrix(arr);
    return 0;
}