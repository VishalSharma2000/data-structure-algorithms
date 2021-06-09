#include <bits/stdc++.h>
using namespace std;

class Edge {
  public:
    int weight;
  int dest;
  Edge *next;

  
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
        adj[dest].push_back(Edge(src, weight));
    }

    void printGraph() {
      for(int i=0; i<V; i++) {
        cout << i << ": ";
        for(int j=0; j<adj[i].size(); j++) {
          cout << adj[i][j].dest << "(" << adj[i][j].weight << ") -> ";
        }
        cout << endl;
      }
    }
};

int main() {
    int v, e;
    cin >> v >> e;
    
    Graph g(v);
    for(int i=0; i<e; i++) {
        int u1, u2, w;
        cin >> u1 >> u2 >> w;
        g.addEdge(u1, u2, w);
    }
    
    g.printGraph();
}

/*
Input:
8 9
1 2 28
1 6 10
6 5 25
5 7 24
7 2 14
5 4 22
7 4 18
4 3 12
2 3 16

Output:
0: 
1: 2(28) -> 6(10) -> 
2: 1(28) -> 7(14) -> 3(16) -> 
3: 4(12) -> 2(16) -> 
4: 5(22) -> 7(18) -> 3(12) -> 
5: 6(25) -> 7(24) -> 4(22) -> 
6: 1(10) -> 5(25) -> 
7: 5(24) -> 2(14) -> 4(18) -> 
*/
