/*
Time Complexity: O(N^2)
*/

#include <bits/stdc++.h>
using namespace std;

int findNextMinCostVertex(int *costToReachVertex, bool *includedVertex, int v) {
    // int v = sizeof(costToReachVertex) / sizeof(costToReachVertex[0]);

    int minCost = INT_MAX, minCostVertex;

    for(int i=0; i<v; i++) {
        if(!includedVertex[i] && costToReachVertex[i] < minCost) 
            minCost = costToReachVertex[i], minCostVertex = i;
    }

    return minCostVertex;
}

void printMST(vector<vector<int>> &adjMat) {
    int v = adjMat.size();

    int parent[v]; // to store the mst
    int costToReachVertex[v];
    bool includedVertex[v];
    for(int i=0; i<v; i++) includedVertex[i] = false;
    for(int i=0; i<v; i++) costToReachVertex[i] = INT_MAX;
    costToReachVertex[0] = 0; // since we are starting to find the mst from vertex 0,
    // hence the cost to reach vertex 0 is 0
    parent[0] = -1;

    for(int i=0; i<v-1; i++) {
        int nextMinCostVertex = findNextMinCostVertex(costToReachVertex, includedVertex, v);

        includedVertex[nextMinCostVertex] = true;
        
        // if the graph is implemented using adjacency matrix, then use the below for loop
        for(int i=0; i<v; i++) {
            if(adjMat[nextMinCostVertex][i] != 0 && !includedVertex[i] && adjMat[nextMinCostVertex][i] < costToReachVertex[i]) {
                parent[i] = nextMinCostVertex;
                costToReachVertex[i] = adjMat[nextMinCostVertex][i];
            }
        }
        
        // if the graph is implemeneted using adjacency list, then use the below loop
        for(Vertex u : adj[nextMinCostVertex]) {
            // basically we are updating the reachability cost of the vertices which can be reached from the vertex (nextMinCostVertex)
            // this is also called relaxation
            // Vertex is a class object with following public values => dest (to store the vertex name), weight (to store the cost to reach the vertex from neighbour)
            
            if(u.weight < costToReachVertex[u.dest]) {
                costToReachVertext[u.dest] = u.weight;
                parent[u.dest] = nextMinCostVertex;
            }
        }
        
        /*
        Note: Both the for loop are performing the same operation, both are only differing in the way of traversing or reaching their neigbours
        */
    }

    for(int i=1; i<v; i++) {
        cout << parent[i] << " " << i << " - " << adjMat[i][parent[i]] << endl;
    }
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adjMat(v, vector<int> (v, 0));
    for(int i=0; i<e; i++) {
        int u1, u2, w;
        cin >> u1 >> u2 >> w;
        adjMat[u1][u2] = w;
        adjMat[u2][u1] = w;
    }

    printMST(adjMat);

    return (0);
}
