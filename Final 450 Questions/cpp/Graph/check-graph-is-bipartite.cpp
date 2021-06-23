/* 
  Graph is bipartite or not can be checked with the help of both the traversal. 
  BFS and DFS
  A graph is called bipartite only if it can be colored using exactly two colors. 
*/

#include <bits/stdc++.h>
using namespace std;

bool bipartiteBFS(vector<int> adj[], int node, vector<int> &color) {
  /* Do normal bfs */
  queue<int> q;

  color[node] = 0;
  q.push(node);

  while(!q.empty()) {
    int u = q.front();
    q.pop();

    /* Do for all its adjacent */
    for(int v : adj[u]) {
      if(color[v] == -1) {
        color[v] = 1 - color[u];
        q.push(v);
      } else if(color[v] == color[u]) return false;
    }
  }

  return true;
}

bool bipartiteDFS(vector<int> adj[], int node, int nodeClr, vector<int> &color) {
  color[node] = nodeClr;

  for(int v : adj[node]) {
    if(color[v] == -1) {
      if(!bipartiteDFS(adj, v, 1 - color[node], color)) return false;
    } else if(color[v] == color[node]) return false;
  }

  return true;
}

/* Another way of writing the function */
bool bipartiteDFS(vector<int> adj[], int node, vector<int> &color) {
  if(color[node] == -1) color[node] = 1;

  for(int v : adj[node]) {
    if(color[v] == -1) {
      color[v] = 1 - color[node];
      if(!bipartiteDFS(adj, v, color)) return false;
    } else if(color[v] == color[node]) return false;
  }

  return true;
}

bool isBipartite(vector<int> adj[], int V) {
  vector<int> color(V+1, -1);

  /* Check for all the disconnected components too */
  /* Taking 1 based indexing */
  for(int i=1; i<=V; i++) {
    if(color[i] == -1) {
      if(!bipartiteBFS(adj, i, color)) return false;
      // if(!bipartiteDFS(adj, i, 0, color)) return false;
    }
  }

  return true;
}

int main() {
  vector<int> adj[] = {{}, {2,5}, {1,3}, {2,4}, {3,5}, {1,4}};
  int size = 4;
  cout << isBipartite(adj, size);
}
