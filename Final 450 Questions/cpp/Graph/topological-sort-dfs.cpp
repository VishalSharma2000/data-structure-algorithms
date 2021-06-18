/* Assuming 1 based indexing of graph nodes */
#include <bits/stdc++.h>
using namespace std;

void getTopologicalSortUtil(vector<int> adj[], int node, vector<bool> &visited, stack<int> &topo) {
  visited[node] = true;

  for(int v : adj[node]) {
    if(!visited[v])
      getTopologicalSortUtil(adj, v, visited, topo);
  }

  topo.push(node);
}

vector<int> getTopologicalSort(vector<int> adj[], int V) {
  stack<int> topo;
  vector<bool> visited(V+1, false);

  /* Doing for all components */
  for(int i=1; i<=V; i++) {
    if(!visited[i]) {
      getTopologicalSortUtil(adj, i, visited, topo);
    }
  }

  vector<int> ans;
  while(topo.size() > 0) {
    ans.push_back(topo.top());
    topo.pop();
  }

  return ans;
}

int main() {
  vector<int> adj[] = {{}, {}, {}, {4}, {2}, {1,2}, {1,3}};
  int v = 6;
  vector<int> topo(getTopologicalSort(adj, v));
  for(int v : topo) cout << v << " ";  
}