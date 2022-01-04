/* Given a weighted graph find the shortest path from source to all other vertices using dijkstra algorithm */
/* Dijkstra algorithm is also bfs - just in place of queue we are using priority_queue to find the shortest path in weighted graph */
/* We can use dijkstra algorithm in all types of graph - directed weighted cyclic and acyclic, undirected weighted cyclic */
/* For acyclic undirected graph, no algorithm is required to find shortest path because there exist only one path
from source to all destination */
/* For DAG (Directed Acyclic Graph), we can find the shortest path using topo sort + bfs - time complexity - O(E + V) - lesser than
dijkstra algorithm */


/* Time complexity: O(E*Log(V)) */
#include <bits/stdc++.h>
using namespace std;

void shortestPath(vector<pair<int, int>> adjList[], int V, int src) {
  vector<int> dist(V, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  dist[src] = 0;
  pq.push({ 0, src });

  while(!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for(pair<int, int> e : adjList[u]) {
      int v = e.first, w = e.second;

      if(dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        pq.push({ dist[v], v });
      }
    }
  }

  for(int i=0; i<V; i++) {
    cout << dist[i] << " ";
  }
  cout << endl;
}

int main() {
  int v, e; cin >> v >> e;

  vector< pair<int, int> > adjList[v];

  for(int i=0; i<e; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adjList[u].push_back({v, w});
    adjList[v].push_back({u, w});
  }

  shortestPath(adjList, v, 0);
}

/* 9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7 */