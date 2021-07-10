/* Print all the connected components of the graph */
#include <bits/stdc++.h>
using namespace std;

/* Time Complexity: O(V + E), Space Complexity: O(V + E) - CallStack */
/* It's actually normal dfs, just we have added a cout statement to print the nodes */

void dfsUtil(vector<int> adj[], int u, vector<bool> &visited) {
  cout << u << " ";     // extra cout to just print the node

  visited[u] = true;
  for(int v : adj[u]) {
    if(!visited[v])
      dfsUtil(adj, v, visited);
  }
}

void printAllConnectedComponents(vector<int> adj[], int V) {
  /* Do Normal DFS for all unvisited nodes */

  vector<bool> visited(V, false);

  for(int i=0; i<V; i++) {
    if(!visited[i]) {
      cout << endl; // extra cout for printing all connected components node on new line
      dfsUtil(adj, i, visited);
    }
  }
}

int main() {
  int V, E;
  cin >> V >> E;

  vector<int> adj[V];
  for(int i=0; i<E; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  printAllConnectedComponents(adj, V);
}