class Graph {
    private:
        int V;
        vector<int> *adj;
    public:
        Graph(int v) {
            V = v;
            adj = new vector<int> [V];
        }
    
        void addEdge(int v1, int v2) {
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
    
        bool DFSUtil(int src, vector<bool> &visited, vector<int> &vDegree, int k) {
            visited[src] = true;
            
            for(int v : adj[src]) {
                if(vDegree[src] < k) {
                    /* if degree of src less than k decrement the degree of all the 
                    neighbours by 1*/
                    vDegree[v]--;
                    /*Note: we are not checking that the adjacent node is visited or 
                    not... if the src degree is less then k then we are directly
                    decrementing the degress of its vertices by 1
                    Also note that we are not actually manipulating the original graph
                    we are just storing the degree in the array and changing the degree
                    of the nodes*/
                }
                
                if(!visited[v]) {
                    /* after processing the neighbour, if its degree become less than 
                    k then we should decrease the degree of current node too*/
                    if(DFSUtil(v, visited, vDegree, k)) 
                        vDegree[src]--;
                }
            }
            
            return (vDegree[src] < k);
        }
    
        void printKCores(int k) {
            vector<bool> visited(V, false);
            vector<int> vDegree(V, 0);
            
            int minDeg = INT_MAX;
            int startIndex = 0;
            for(int i=0; i<V; i++) {
                vDegree[i] = adj[i].size();
                
                if(vDegree[i] < minDeg) {
                    minDeg = vDegree[i];
                    startIndex = i;
                }
            }
            /* Finding minimum degree is not a compulsion here, its only to optimize 
            the process a bit, bcoz the starting vertex will have a higher chance of having 
            degree less than k
            We can start from any vertex but in that case, their may be chance that initial
            vertexes may have degree more than k*/
            
            DFSUtil(startIndex, visited, vDegree, k);
            
            /* the below for loop is only needed when the graph may have disconnected 
            components or if we do not find minDeg and startIndex explicity(if we do not do then the above call can be vertex with deg more than k)*/
            
            for(int i=0; i<V; i++) 
                if(!visited[i])
                    DFSUtil(i, visited, vDegree, k);
            
            // print the k codes
            for(int v=0; v<V; v++) {
                if(vDegree[v] >= k) {
                    cout << "\n[" << v << "] ";
                    
                    for(int u : adj[v]) {
                        if(vDegree[u] >= k) 
                            cout << "->" << u;
                    }
                }
            }
        }
};

int main() {
    Graph g1(9); 
    g1.addEdge(0, 1); 
    g1.addEdge(0, 2); 
    g1.addEdge(1, 2); 
    g1.addEdge(1, 5); 
    g1.addEdge(2, 3); 
    g1.addEdge(2, 4); 
    g1.addEdge(2, 5); 
    g1.addEdge(2, 6); 
    g1.addEdge(3, 4); 
    g1.addEdge(3, 6); 
    g1.addEdge(3, 7); 
    g1.addEdge(4, 6); 
    g1.addEdge(4, 7); 
    g1.addEdge(5, 6); 
    g1.addEdge(5, 8); 
    g1.addEdge(6, 7); 
    g1.addEdge(6, 8); 
    g1.printKCores(3); 
}
