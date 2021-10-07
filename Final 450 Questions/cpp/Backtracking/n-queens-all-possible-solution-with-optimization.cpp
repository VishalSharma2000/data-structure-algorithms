#include <bits/stdc++.h>
using namespace std;

const int n = 5;
vector<vector<int>> allSolution;
int ld[2*n+1], rd[2*n+1], currRow[n];

/* 
left diagonal contanst value is => i+col
right diagonal constant value is => i-col+n-1

for n = 5
left diagonal values
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9
6 7 8 9 10

so value range from [2, 2*n]

right diagonal values (with only i-col)
0 -1 -2 -3 -4
1  0 -1 -2 -3
2  1  0 -1 -2
3  2  1  0 -1
4  3  2  1  0

after adding n-1

4 3 2 1 0
5 4 3 2 1
6 5 4 3 2
7 6 5 4 3
8 7 6 5 4
*/

bool isSafe(int row, int col, bool board[][n]) {
  for(int i=0; i<col; i++)
    if(board[row][i]) return false;

  int i = row, j = col;
  while(i >=0 && j >=0) {
    if(board[i][j]) return false;

    i--;
    j--;
  }

  i = row, j = col;
  while(i < n && j >= 0) {
    if(board[i][j]) return false;

    i++;
    j--;
  }

  return true;
}

bool isSafeOptimized(int row, int col) {
  if(currRow[row]) return false;
  if(ld[row+col]) return false;
  if(rd[row-col+n-1]) return false;

  return true;

  // another way to write the same logic
  // return !(currRow[row] || ld[row+col] || rd[row-col+n-1]);
}

void getAllPossibleNQueenPosition(int col, vector<int> &pos) {
  if(col == n) {
    allSolution.push_back(pos);
    return;
  }

  for(int i=0; i<n; i++) {
    if(isSafeOptimized(i, col)) {
      currRow[i] = 1;
      ld[i+col] = 1;
      rd[i-col+n-1] = 1;

      pos.push_back(i);
      getAllPossibleNQueenPosition(col+1, pos);
      pos.pop_back();

      currRow[i] = 0;
      ld[i+col] = 0;
      rd[i-col+n-1] = 0;
    }
  }
}

int main() {
  vector<int> pos;
  getAllPossibleNQueenPosition(0, pos);

  cout << allSolution.size() << endl;
  for(vector<int> sol : allSolution) {
    for(int val : sol) cout << val+1 << " ";
    cout << endl;
  }
}