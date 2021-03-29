#include <bits/stdc++.h>
using namespace std;


void SSSP(vector<int> adj[], int V, int src) {
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
            
        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                distance[v] = distance[u] + 1;
                parent[v] = u;

                q.push(v);
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
        cout << endl;
    }
}

int main() {
    int e, v;
    cin >> v >> e;
    
    vector<int> adj[v];
    for(int i=0; i<e; i++) {
        int u1, u2;
        cin >> u1 >> u2;
        adj[u1].push_back(u2);
        // adj[u2].push_back(u1);
    }
    
    for(int i=0; i<v; i++) {
      cout << i << "->";
      for(int u : adj[i]) {
        cout << u << " ";
      }
      cout << endl;
    }

    SSSP(adj, v, 0);
}