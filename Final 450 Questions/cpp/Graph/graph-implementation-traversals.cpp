#include <bits/stdc++.h>
using namespace std;

/* One small difference in bfs and dfs is...when we do dfs we make the node visited when we reach at that node but in
bfs we make the node x visited when we are at its adjacent node */
/* 
    Adjacency List => O(N + 2*E)
    1 -> lists of adjacent
    2 -> lists of adjacent

    when we do sum of all list of adjacenet => 2 * E
 */

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
    
    void DFSUtil(int node, bool visited[]) {
        // mart the current node as visited
        visited[node] = true;
        cout << node << " ";
        
        // recursively call its neighbour
        for(auto u : adj[node]) {
          // if the neighbour is not visited, then recursively call the function for it, else continue with other neighbour
            if(visited[u] == false)
                DFSUtil(u, visited);
        }
    }
    
    void DFS(int node) {
        bool *visited = new bool[V];
        for(int i=0; i<V; i++) visited[i] = false;
        
        DFSUtil(node, visited);
    }


    /* Print all the connected components of the graph */
    void printAllConnectedComponents() {
        bool visited[V];
        memset(visited, false, sizeof(visited));

        /* The below for-loop and if-loop structure says if the component starting with index i is not visited
        then visit the component */
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                DFSUtil(i, visited);
                cout << endl;
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
    G.BFS(0); cout << endl;
    G.DFS(0);

    G.printAllConnectedComponents();
}
