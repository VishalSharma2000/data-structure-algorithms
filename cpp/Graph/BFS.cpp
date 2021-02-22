// BFS Traversal of the graph
class Graph {
  public:
    int V;
    list<int> *adj;
    
    Graph(int vertices) {
        V = vertices;
        adj = new list<int>[V]; // array of doubly linked list
    }
    
    void addEdge(int src, int dest) {
        adj[src].push_back(dest);
        // if the graph is undirecteed
        adj[dest].push_back(src);
    }
    
    void printGraph() {
        for(int i=0; i<V; i++) {
            cout << i << "->";
            for(auto v : adj[i]) 
                cout << v << "-";
            
            cout << endl;
        }
    }
    
    void BFS(int src) {
        list<int> queue; // queue implementation using doubly linked list
        // visited array to keep track of which vertices is visited 
        bool *visited = new bool[V];
        for(int i=0; i<V; i++) visited[i] = false;
        
        // visiting the src node
        queue.push_back(src);
        visited[src] = true;
        
        while(!queue.empty()) {
            int currNode = queue.front();
            queue.pop_front();
            cout << currNode << " ";
            
            // visit all the neigbours of the currNode which are not visited.
            // If the vertices is not visited then push it into queue, to iteratively
            // again visit the neighbours of that node and so on...
            for(auto u : adj[currNode]) {
                if(!visited[u]) {
                    visited[u] = true;
                    queue.push_back(u);
                }
            }
            
        }
    }
};

int main() {
    int v, e; cin >> v >> e;
    Graph G(v);
    
    for(int i=0; i<e; i++) {
        int src, dest;
        cin >> src >> dest;
        
        G.addEdge(src, dest);
    }
    
    G.printGraph();
    G.BFS(0);
}
