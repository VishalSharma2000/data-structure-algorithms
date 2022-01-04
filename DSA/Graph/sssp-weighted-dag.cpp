/* Given a src and a directed acylic graph(DAG) find the distance from source to all the other nodes  */
/* Approach : Find Topological Sort => Do BFS */
/* Time complexity: O(2*(N + E)) - one for topological sort and one for bfs
  Space Complexity: O(2N)
*/

#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX

void dfsUtil(vector<pair<int, int>> adj[], int node, vector<bool> &visited, stack<int> &topo) {
  visited[node] = true;

  for(pair<int, int> e : adj[node]) {
    if(!visited[e.first])
      dfsUtil(adj, e.first, visited, topo);
  }

  topo.push(node);
}

stack<int> getTopologicalSort(vector<pair<int, int>> adj[], int V) {
  vector<bool> visited(V, false);
  stack<int> topo;

  /* For loop for all components */
  for(int i=0; i<V; i++) {
    if(!visited[i])
      dfsUtil(adj, i, visited, topo);
  }

  return topo;
}

void shortestDistFrom(vector<pair<int, int>> adj[], int V, int src) {
  /* Find topological sort to reduce the reduntant traversing of nodes - see notes */
  stack<int> topo(getTopologicalSort(adj, V));
  vector<int> distance(V, INF);

  distance[src] = 0;

  while(!topo.empty()) {
    int u = topo.top();
    topo.pop();

    /* Handling disconnected components */
    if(distance[u] != INF) {
      for(pair<int, int> e : adj[u]) {
        if(distance[e.first] > distance[u] + e.second)
          distance[e.first] = distance[u] + e.second;
      }
    }
  }

  for(int i=0; i<V; i++) cout << distance[i] << " ";
  cout << endl;
}

int main() {
  int V, E;
  cin >> V >> E;

  /* Initialize pair of vector to make the adjacancy list of graph <edgeName, weight> */  
  vector<pair<int, int> > adj[V];
  for(int i=0; i<E; i++) {
    int u1, u2, w;
    cin >> u1 >> u2 >> w;

    /* Directed Weigthed Graph */
    adj[u1].push_back({u2, w});
  }  

  shortestDistFrom(adj, V, 0);
}


/* 
input:
  6 7
0 1 2
0 4 1
1 2 3
4 2 2
4 5 4
2 3 6
5 3 1

output: 
0 2 3 6 1 5
 */