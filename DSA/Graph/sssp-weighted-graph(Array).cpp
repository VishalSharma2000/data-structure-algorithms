#include <bits/stdc++.h>
using namespace std;

class Edge {
  public:
    int dest, weight;

    Edge(int d, int w) {
      dest = d;
      weight = w;
    }
};

int closestVertex(vector<int> distance, vector<int> inlcudedVertex) {
  int minIndex, minCost = INT_MAX;

  for(int i=0; i<distance.size(); i++) {
    if(!inlcudedVertex[i] && distance[i] < minCost) {
      minCost = distance[i];
      minIndex = i;
    }
  }

  return minIndex;
}

void dijkstra(vector<Edge> adj[], int V) {
  vector<int> distance(V); // to store the distance from src to every other vertex
  vector<int> includedVertex(V, false); // will contain all the vertex which has been included 
  vector<int> parent(V);

  for(int i=0; i<V; i++) parent[i] = i;

  distance[0] = 0;
  includedVertex[0] = true;
  parent[0] = -1;

  for(int i=0; i<V-1; i++) {
    int u = closestVertex(distance, includedVertex);

    includedVertex[u] = true;

    for(Edge v : adj[u]) {
      if(!includedVertex[v.dest] && distance[v.dest] > distance[u] + v.weight) {
        distance[v.dest] = distance[u] + v.weight;

        parent[v.dest] = u;
      }
    }
  }

  cout << "All Shortest Path are: " << endl;
  for(int i=0; i<V; i++) {
      int node = i;
      
      vector<int> path;
      while(node != -1) {
          path.push_back(node);
          node = parent[node];
      }
      cout << "Path from 0 to " << i << ": ";
      for(int m=path.size()-1; m>=0; m--) cout << path[m] << " ";
      cout << "\nDistance: " << distance[i] << endl;
  }
}

int main() {
  int e, v;
  cin >> v >> e;
  
  vector<Edge> adj[v];
  for(int i=0; i<e; i++) {
      int u1, u2, w;
      cin >> u1 >> u2 >> w;
      adj[u1].push_back(Edge(u2, w));
      adj[u2].push_back(Edge(u1, w));
  }

  dijkstra(adj, v);
}