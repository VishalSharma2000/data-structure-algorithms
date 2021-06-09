/*
I have tried to implement the Prim's Algorithm on my own
Problems Distributions I found while implementing on my own
1) Representation of weighted undirected graph => for solving this problem I made some changes in the adj list data structure. I added one more value into edge 
class to store the weight
2) According to prim's algorithm, in each iteration we should form a connected graph(in other words - we should choose such an edge which has least weight and
should be conected with the present mst and should not form a cycle). So, the problem here..how to find the edge with such constraint. => For solving this problem 
I used brute force approch of comparing the weights of all the visited node and find the edge with minimum weight
Another problem here was to => how to find that the current edge will result into cycle or not...
So, its basically detecting graph in undirected graph..so for this i used disjoint set algorithm...
*/

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

class DisjointSet {
    public:
        vector<int> parent;
    
        DisjointSet(int v) {
            parent.resize(v);
            for(int i=0; i<v; i++) parent[i] = i; // making different set.
        }
    
        int findParent(int v) {
            if(parent[v] == v) return v;
            
            return findParent(parent[v]);
        }
    
        bool performUnion(int v1, int v2) {
            int parentV1 = findParent(v1);
            int parentV2 = findParent(v2);
            
            if(parentV1 == parentV2) return false;
            // cycle will be formed
            
            parent[parentV1] = parentV2;
            return true;
        }
    
        bool checkCycleWillBeFormed(int v1, int v2) {
            int parentV1 = findParent(v1);
            int parentV2 = findParent(v2);
            
            return parentV1 == parentV2;
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
    
    /* Using Disjoint set data structure to keep track that including any edge
    doesn't result into the cycle 
    Since, we don't need full disjoint set data structure we only need some functions...we will create them manually */
    vector<int> getMST(int src) {
        vector<bool> visited(V, false);
        vector<int> mst;
        int cost = 0;
        
        mst.push_back(src);
        visited[src] = true;
    
    DisjointSet DS(V);
    
    Edge minEdge(INT_MAX, INT_MAX);
    for(int count=0; count <V-1; count++) {
    minEdge.dest = INT_MAX;
        minEdge.weight = INT_MAX;
        // now the first loop will run for other left vertices which is v-1 times
        for(int i=0; i<V; i++) {
    // finding the edge with minimum weight from all the edges which are connected to already visited edges
            if(visited[i]) {
                for(Edge u : adj[i]) {
                    if(u.weight < minEdge.weight) {
                        if(!DS.checkCycleWillBeFormed(u.dest, src))
                            minEdge = u;   
                    }
                }   
            }
         }
        
        DS.performUnion(src, minEdge.dest);
        visited[minEdge.dest] = true; 
        mst.push_back(minEdge.dest);
        cost += minEdge.weight;
    }
    
        cout << cost << endl;
    return mst;
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
    vector<int> MST(g.getMST(1));
    for(int i=0; i<MST.size(); i++) cout << MST[i] << " ";
    cout << endl;
}
