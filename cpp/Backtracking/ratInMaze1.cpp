/*
Main idea : BFS

Time complexity  O(3 ^ (n^2))
Space complexity  O(3 ^ (n^2))
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 100

bool isSafe(int row, int col, int arr[][MAX], int n, bool visited[][MAX]) {
  if(row == -1 || row == n || col == -1 || col == n || visited[row][col] || arr[row][col] == 0) {
    return false;
  }
  return true;
}

void findPaths(int row, int col, int arr[][MAX], int n, vector<string> &possiblePaths, string &path, bool visited[][MAX]) {
  // breaking condition
  if(row == -1 || row == n || col == -1 || col == n || visited[row][col] || arr[row][col] == 0) {
    return;
  }

  // accepting condition
  if(row == n-1 && col == n-1) {
    possiblePaths.push_back(path);
    return;
  }

  visited[row][col] = true;

  /* 
  if we call the findPaths function directly without checking if the next path is valid or not, then being a recursive solution
  we will get the solution in reverse order. Bcoz we cannot directly go to next step without checking that the next pos is valid or 
  not. 
  So, the recursive func call will be done beforep pushing the path ('D', 'U', ...).

  To avoid this, we are creating a isSafe() func to check if the next path is valid or not, then we are accordingly calling the func
  findPaths
  */

  if(isSafe(row+1, col, arr, n, visited)) {
    path.push_back('D');
    findPaths(row+1, col, arr, n, possiblePaths, path, visited);
    path.pop_back();
  }

  if(isSafe(row, col-1, arr, n, visited)) {
    path.push_back('L');
    findPaths(row, col-1, arr, n, possiblePaths, path, visited);
    path.pop_back();
  }

  if(isSafe(row, col+1, arr, n, visited)) {
    path.push_back('R');
    findPaths(row, col+1, arr, n, possiblePaths, path, visited);
    path.pop_back();
  }

  if(isSafe(row-1, col, arr, n, visited)) {
    path.push_back('U');
    findPaths(row-1, col, arr, n, possiblePaths, path, visited);
    path.pop_back();
  }

  /*
  In usual BFS, we don't again make the visited node as unvisited, here we are doing bcoz we want to find different paths...
  so, after completing one full branch of node...we can again come to that node through different path.
  */

  visited[row][col] = false;
}

vector<string> getAllPaths(int arr[][MAX], int n) {
  vector<string> possiblePaths;
  string path;
  bool visited[n][MAX] = {false};

  findPaths(0, 0, arr, n, possiblePaths, path, visited);
  return possiblePaths;
}

int main() {
  int n; cin >> n;

  int arr[MAX][MAX];
  for(int i=0; i<n; i++) 
    for(int j=0; j<n; j++) 
      cin >> arr[i][j];
    
  vector<string> possiblePaths;
  possiblePaths = getAllPaths(arr, n);

  for(string path: possiblePaths) cout << path << " ";
  return 0;
}