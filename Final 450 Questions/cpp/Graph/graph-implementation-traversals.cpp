#include <bits/stdc++.h>
using namespace std;

/* 
Adjacency List contains data about all the neighbours of all the vertices 
1 -> { list of all neighbouring nodes }
2 -> { list of all neighbouring nodes }
and so on

Space for adjacency list => O(V + 2*E)
V => for all the vertices
2*E = 2*(V^2) => in worst case when the graph is complete then each vertex will have V-1 neighbours and in adjaceny list each edge will be repeated twice. 

eg:
1 -> 2, 3, 4
2 -> 1, 3
3 -> 1, 2
4 -> 1

above is the adjacency list of undirected graph.
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
    
    /* Breadth First Search Traversal => TC: O(E+V), SC: O(E) */
    void BFS(int src) {
        list<int> queue;                    // queue implementation using doubly linked list
        bool *visited = new bool[V];        // visited array to keep track of which vertices is visited 
        for(int i=0; i<V; i++) visited[i] = false;
        
        // visiting the src node
        queue.push_back(src);
        visited[src] = true;
        
        while(!queue.empty()) {
            int currNode = queue.front();
            queue.pop_front();
            cout << currNode << " ";
            
            /* visit all the unvisited neigbours of the currentNode and also push it into the queue */
            for(auto u : adj[currNode]) {
                if(!visited[u]) {
                    visited[u] = true;      // mark as visited
                    queue.push_back(u);
                }
            }
            
        }
    }
    
    /* Depth First Search Traversal - TC:O(E + V), SC: O(V) */
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
