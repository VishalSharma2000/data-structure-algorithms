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

void zeroOneBFS(vector<Edge> adj[], int V) {
  // since the edges weights are constrained to 0 or 1
  // we instead of finding the weight with minium edge we are using doubly ended queue...so that the edge with cost
  // 0 can be pushed from front and the edge with weight 1 from back

  deque<int> Q;
  int distance[V];

  for(int i=0; i<V; i++) distance[i] = INT_MAX;

  distance[0] = 0;
  Q.push_front(0);

  while(!Q.empty()) {
    int v = Q.front();
    Q.pop_front();

    /*
      If we get an edge from where other paths cost can be reduced then we will again push that 
      edge into the queue...hence one edge can be visited more than once here...
    */
    for(Edge u : adj[v]) {
      if(distance[u.dest] > distance[v] + u.weight) {
        distance[u.dest] = distance[v] + u.weight;

        if(u.weight == 0) Q.push_front(u.dest);
        else Q.push_back(u.dest);
      }
    }

    for(int i=0; i<V; i++) cout << distance[i] << " ";
    cout << endl;
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

  zeroOneBFS(adj, v);
}