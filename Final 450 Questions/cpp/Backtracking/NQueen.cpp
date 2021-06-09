/*
  We will try to keep all the queens column by column starting from 0 to N-1, 
  For every col, we will travers over all rows and find a row where placing the queen won't create a clash...
  If no such row exist, then we will backtrack and try to keep the previous queen at some other position and try again.

  Time complexity: O(n ^ (n * n))
*/

#include <bits/stdc++.h>
using namespace std;

#define N 8

bool isSafe(int row, int col, bool board[][N]) {
  // check if any queen is already present in row in all preceding columns = row
  for(int i=0; i<col; i++)
    if(board[row][i])
      return false;
    
  // check if their is any queeon on the upper diagonal from (row, col)
  for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
    if(board[i][j]) 
      return false;
  } 

  // check if their is any queen at lower diagonal from (row, col)
  for(int i=row, j=col; i<N && j>=0; i++, j--) {
    if(board[i][j]) 
      return false;
  }

  return true;
}

int solveNQueenUtil(int col, bool board[][N]) {
  if(col == N) return 1; // all queens place properly

  for(int i=0; i<N; i++) {
    if(isSafe(i, col, board)) {
      board[i][col] = true;

      if(solveNQueenUtil(col+1, board) == 1)
        return 1;
      else 
        board[i][col] = false; // backtracking
    }
  }

  return 0;  
}

void printBoard(bool board[N][N]) {
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) 
      cout << board[i][j] << " ";
    cout << endl;
  }
}

void solveNQueen() {
  // to store the position of the queen
  bool board[N][N] = {false};

  if(solveNQueenUtil(0, board) == 1)
    printBoard(board);
  else 
    cout << -1 << endl;

  return;
}

int main() {
  solveNQueen();
  return 0;
}