/* Find topological sort of the graph using bfs traversal also called as kahn algorithm */

#include <bits/stdc++.h>
using namespace std;

/* 1 based indexing of the graph */
vector<int> getTopologicalSort(vector<int> adj[], int V) {
  vector<int> indegree(V+1, 0);

  for(int i=1; i<=V; i++) {
    for(int u : adj[i])
      indegree[u]++;
  }

  queue<int> q;
  for(int i=1; i<=V; i++) 
    if(indegree[i] == 0) 
      q.push(i);

  int cnt = 0;
  while(!q.empty()) {
    int u = q.front();
    q.pop();
    cnt++;

    for(int v : adj[u]) {
      indegree[v]--;

      if(indegree[v] == 0) {
        q.push(v);
      }
    }
  }

  /* If cnt == N then topological sort exist hence graph does not contain cycle
  else graph contain cycle */
  return !(cnt == N);
}

int main () {
  vector<int> adj[] = {{}, {}, {}, {4}, {2}, {1,2}, {1,3}};
  int v = 6;
  cout << getTopologicalSort(adj, v)
}