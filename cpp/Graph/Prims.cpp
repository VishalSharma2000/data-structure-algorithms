#include <bits/stdc++.h>
using namespace std;

class Edge {
  int weight;
  int dest;
  Edge *next;

  public:
    Edge (int d, int w) {
      weight = w;
      dest = d;
      next = NULL;
    }
};

class Graph {
  private:
    int V;
    vector<vector<Edge>> adj;
  public:
    Graph(int v) {
      V = v;
      adj.resize(V);
    }

    void addEdge(int src, int dest, int weight) {
      adj[src].push_back(Edge(dest, weight));
    }

    void printGraph() {
      for(int i=0; i<V; i++) {
        cout << i << ": ";
        for(int j=0; j<adj[i].size(); j++) {
          cout << adj[i][j] << "->";
        }
        cout << endl;
      }
    }
};

int main() {
  int v, e;
}