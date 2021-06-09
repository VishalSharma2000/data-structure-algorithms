/*
Mother Vertex is that vertex of the graph from where we can reach every other node of the graph
*/
void dfsUtil(vector<int> adj[], int src, vector<bool> &visited) {
    visited[src] = true;
    
    for(int v : adj[src]) {
        if(!visited[v]) 
            dfsUtil(adj, v, visited);
    }
}

int findMotherVertex(vector<int> adj[], int v) {   
    for(int i=0; i<v; i++) {
        vector<bool> visited(v, false);
        
        dfsUtil(adj, i, visited);
        
        // check if all the vertices are visited or not...
        bool status = true;
        for(int j=0; j<v; j++) 
            if(visited[j] == false) { status = false; break; }
        
        if(status) return i;
    }
    
    return -1;
}

int main() {
    int v, e;
    cin >> v >> e;
    
    vector<int> adj[v];
    
    for(int i=0; i<e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        
        adj[v1].push_back(v2);
    }
    
    cout << findMotherVertex(adj, v) << endl;
}
