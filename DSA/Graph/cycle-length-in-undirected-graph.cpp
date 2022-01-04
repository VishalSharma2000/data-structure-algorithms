#include <bits/stdc++.h>
using namespace std;

bool isCyclePresentDFS(vector<int> adj[], int node, vector<bool> &visited, vector<bool> &currDFS) {
  visited[node] = true;
  currDFS[node] = true;

  for(int v : adj[node]) {
    if(!visited[v]) {
      if(isCyclePresentDFS(adj, v, visited, currDFS)) return true;
    } else if(visited[v] && currDFS[v]) return true;
  }

  currDFS[node] = false;
  return false;
}

bool isCyclePresent(vector<int> adj[], int V) {
  vector<bool> visited(V+1, false);
  vector<bool> currDFS(V+1, false);

  /* Doing for all the components */
  for(int i=1; i<=V; i++) {
    if(!visited[i]) {
      if(isCyclePresentDFS(adj, i, visited, currDFS)) {
        int len = 0;
        for(bool status : currDFS) {
          if(status) len++;
        }

        cout << len << endl;
      }
    }
  }

  return false;
}

int main() {
  int v, e;
  cin >> v >> e;

  vector<int> adj[v+1];
  for(int i=0; i<e; i++) {
    int u1, u2;
    cin >> u1 >> u2;
    
    adj[u1].push_back(u2);
    adj[u2].push_back(u1);
  }

  cout << isCyclePresent(adj, v) << endl;
}