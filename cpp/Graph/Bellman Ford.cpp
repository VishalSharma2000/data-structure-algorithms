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

void bellmanFord(vector<vector<int>> adj, int V) {
    vector<int> distance(V, INT_MAX);
    
    distance[0] = 0;
    
    for(int i=0; i<V-1; i++) {
        vector<int> includedVertex(V, false);
        includedVertex[0] = true;
        
        for(int v=0; v<V-1; v++) {
            int u = minVertex(includedVertex, distance);    
        }
    }
}

int main() {
  int e, v;
  cin >> v >> e;
  
  vector<vector<int>> adj(v, vector<int> (v, 0));
  for(int i=0; i<e; i++) {
      int u1, u2, w;
      cin >> u1 >> u2 >> w;
      adj[u1][u2] = w;
      adj[u2][u2] = w;
  }

  bellmanFord(adj, v);
}
