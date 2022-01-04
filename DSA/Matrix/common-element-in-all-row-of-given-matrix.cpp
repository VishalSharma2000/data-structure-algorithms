/* Brute force appproach is to check for all elements in first row to check if they are present in all other row.
TC: O(n * (m*n)) */
/* 
  We have to basically find the common elements between all the row elements. So, common element should be present in every row.
  So, initially create an unordered map of all first row elements and assign them value 0, stating that they were present in 0thrrow index, 
  so for all further row, first check if the element is present in map using count and next it should be present in the previous row. If the two conditions are satisfied then update the index of the element.

  At the last row, if any element contain index of the 2nd last row then definitely it is common in all row
*/

#include <bits/stdc++.h>
using namespace std;

#define M 4
#define N 5

// TC: O(n*m), SC: O(column size)
void printCommonElements(int mat[][N]) {
    unordered_map<int, int> mp;
    
    for(int i=0; i<N; i++) 
        mp[mat[0][i]] = 0;
    
    for(int i=1; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(mp.count(mat[i][j]) > 0 && mp[mat[i][j]] == (i-1)) {
                mp[mat[i][j]] = i;
                
                if(i == M-1 && mp[mat[i][j]] == M-1) {
                    cout << mat[i][j] << " ";
                }
            }
        }
    }
}

int main() {
    int mat[M][N] =
    {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
 
    printCommonElements(mat);
 
    return 0;
}