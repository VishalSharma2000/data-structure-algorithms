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

void SSSP(vector<Edge> adj[], int V, int src) {
    vector<bool> visited(V, false);
    vector<int> parent(V);
    vector<int> distance(V, 0);
    queue<int> q;
    
    for(int i=0; i<V; i++) parent[i] = -1;
    
    q.push(src);
    visited[src] = true;
    distance[src] = 0;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        /*
        The only difference between SSSP and this code is
        here I'm also checking if the node is visited or not bcoz
        since the weights can be interger we may encounter a path in future which 
        will have less cost...
        so if the node is visited then check if the cost from current node to that node
        is less than the actual cost...if the new cost is less than update the cost
        and again push the vertex into the queue so that it will update the distance 
        to its neighbours too..
        */
        
        for(Edge v : adj[u]) {
            if(!visited[v.dest]) {
                visited[v.dest] = true;
                distance[v.dest] = distance[u] + v.weight;
                parent[v.dest] = u;

                q.push(v.dest);
            } else {
                // if already visited then doing relaxation
                if(v.weight + distance[u] < distance[v.dest]) {
                    distance[v.dest] = v.weight + distance[u];
                    parent[v.dest] = u;
                    
                    q.push(v.dest);
                }
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
    
    // printing the adjacency list
    // for(int i=0; i<v; i++) {
    //   cout << i << "->";
    //   for(Edge u : adj[i]) {
    //     cout << u << " ";
    //   }
    //   cout << endl;
    // }

    SSSP(adj, v, 0);
}

/*
Test Input:
9 14
0 1 0
0 7 1
1 7 1
1 2 1
7 8 1
7 6 1
2 8 1
8 6 1
2 5 0
2 3 0 
6 5 1
3 4 1
3 5 1
5 4 1

All Shortest Path are: 
Path from 0 to 0: 0 
Distance: 0
Path from 0 to 1: 0 1 
Distance: 0
Path from 0 to 2: 0 1 2 
Distance: 1
Path from 0 to 3: 0 1 2 3 
Distance: 1
Path from 0 to 4: 0 1 2 5 4 
Distance: 2
Path from 0 to 5: 0 1 2 5 
Distance: 1
Path from 0 to 6: 0 7 6 
Distance: 2
Path from 0 to 7: 0 7 
Distance: 1
Path from 0 to 8: 0 7 8 
Distance: 2
*/