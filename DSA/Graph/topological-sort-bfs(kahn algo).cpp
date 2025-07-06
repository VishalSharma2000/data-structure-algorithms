/* Find topological sort of the graph using bfs traversal also called as kahn algorithm */

#include <bits/stdc++.h>
using namespace std;

vector<int> getTopologicalSort(vector<vector<int>> adj, int n) {
  vector<int> indegree(n, 0);

  for(int i=0; i<n; i++) {
    for(int u : adj[i])
      indegree[u]++;
  }

  queue<int> q;
  for(int i=0; i<n; i++) 
    if(indegree[i] == 0) 
      q.push(i);

  vector<int> topo;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    topo.push_back(u);

    for(int v : adj[u]) {
      indegree[v]--;

      if(indegree[v] == 0) {
        q.push(v);
      }
    }
  }

  return topo;
}

int main () {
  vector<vector<int>> adj = {{}, {}, {}, {4}, {2}, {1,2}, {1,3}};
  vector<int> topo(getTopologicalSort(adj, adj.size()));
  for(int v : topo) cout << v << " ";  
}
