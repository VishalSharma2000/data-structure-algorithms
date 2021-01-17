/*
  We have a knight at (0, 0) position on chess board, we have to return the path it should follow to travers
  all the blocks of the chess board. 

  Naive approach: Find all the path that the knight can travel on chess board, then for each path check if it is travelling to all the block or not.
  If yes then return that path, if no path exist then return -1

  Backtracking approach is an optimization over naive approach, where we travel in increment way. 
  At any point if the condition is not satisfy, then we go one step ahead and try with different case. In this way we drop the permutation which will not result into the solution.
*/

#include <bits/stdc++.h>
using namespace std;

#define N 8

bool isSafe(int x, int y, int visited[][N]) {
  if(x < 0 || x >= N || y < 0 || y >= N || visited[x][y] != -1) return false;
  return true;
}

void printUtil(int visited[][N]) {
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) 
      cout << visited[i][j] << " ";
    cout << endl;
  }
}

int knightUtil(int x, int y, int movei, int visited[][N], int xMove[], int yMove[]) {
  if(movei == N * N) return 1;

  for(int i=0; i<8; i++) {
    int nextX = x + xMove[i];
    int nextY = y + yMove[i];

    if(isSafe(nextX, nextY, visited)) {
      visited[nextX][nextY] = movei;

      if(knightUtil(nextX, nextY, movei+1, visited, xMove, yMove) == 1)
        return 1;
      else
        // if the further paths are returning 0, then we will make current x and y as not visited, and go for other cases.
        visited[nextX][nextY] = -1;
    }
  }
  
  return 0;
}

void solveKnight (int x, int y) {
  int visited[N][N]; // for storing the jump number;
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) visited[i][j] = -1;

  visited[0][0] = 0;

  // all set of valid knight moves. 
  int xMove[8] = {-1, 1, -2, -2, 1, -1, 2, 2};
  int yMove[8] = {2, 2, -1, 1, -2, -2, -1, 1};

  if(knightUtil(x, y, 1, visited, xMove, yMove) == 1)
    printUtil(visited);
  else 
    cout << -1 << endl;
}

int main() {
  int x, y;
  cin >> x >> y; // input knight position

  solveKnight(x, y);
  return 0;
}