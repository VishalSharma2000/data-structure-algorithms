#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adjList[], int node, vector<bool> &visited, stack<int> &s) {
    visited[node] = true;
    
    for(int u : adjList[node]) {
        if(!visited[u]) 
            dfs(adjList, u, visited, s);
    }
    
    s.push(node);
}

void revDFS(vector<int> tran[], int node, vector<bool> &visited) {
    cout << node << " ";
    visited[node] = true;
    
    for(int u : tran[node]) {
        if(!visited[u]) 
            revDFS(tran, u, visited);
    }
}

void kosaraju(vector<int> adjList[], int V) {
    stack<int> s;
    vector<bool> visited(V, false);
    
    for(int i=0; i<V; i++) {
        if(!visited[i]) 
            dfs(adjList, i, visited, s);
    }
    
    vector<int> tran[V];
    for(int i=0; i<V; i++) {
        for(int u : adjList[i]) {
            tran[u].push_back(i);
        }
    }
    
    fill(visited.begin(), visited.end(), false);
    while(!s.empty()) {
        int u = s.top();
        s.pop();
        
        if(!visited[u]) {
            cout << "SCC: ";
            revDFS(tran, u, visited);
            cout << endl;
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    
    vector<int> adjList[v];
    for(int i=0; i<e; i++) {
        int u, v;
        cin >> u >> v;
        
        adjList[u].push_back(v);
    }
    
    // print all strongly connected component in the graph
    kosaraju(adjList, v);
}