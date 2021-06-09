/*
Finding shortest path from src to all vertices of the graph where the graph can also have negative weights...
If the graph will have negative weight cycle then Bellman Ford Algorithm will tell that to us.

Time Complexity: O(V * E) 
*/
#include <bits/stdc++.h>
using namespace std;

class Edge {
    public:
        int src, dest, weight;
    
    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        weight = w;
    }
};

void bellmanFord(vector<Edge> &edges, int V, int src) {
    int E = edges.size();
    
    vector<int> distance(V, INT_MAX);   // distance from src to vertex v
    vector<int> parent(V);              // to store the parent from srouce to destination vertex and later can be used to print the path
    
    for(int i=0; i<V; i++) parent[i] = i;
    
    distance[src] = 0;
    parent[src] = -1;
    
    for(int i=0; i<V-1; i++) {
        for(int j=0; j<E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            
            /* Here we are first checking for the condition that distance[i] != INT_MAX 
            to avoid overflow...in other algorithms we were first finding the distance
            between the vertices and then relaxation would take place but this is 
            Dynamic Programming approach so we will be handling all the cases here...
            So, if the there is not a path to reach vertex u then distance[u] will be equal to INT_MAX and hence
            distance[u] + weight will be more than INT_MAX hence giving overflow error */
            if(distance[u] != INT_MAX && distance[v] > distance[u] + weight) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
            }
        }
    }
    
    for(int i=0; i<E; i++) {
        int u = edges[i].src, v = edges[i].dest, weight = edges[i].weight;
        
        if(distance[u] != INT_MAX && distance[v] > distance[u] + weight) {
            cout << "Graph Contains negative weight cycle" << endl;
            return;
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
    int v, e;
    
    cin >> v >> e;
    vector<Edge> edges;
    for(int i=0; i<e; i++) {
        int u1, u2, w;
        cin >> u1 >> u2 >> w;
        
        edges.push_back(Edge(u1, u2, w));
    }
    
    bellmanFord(edges, v, 0);
}
