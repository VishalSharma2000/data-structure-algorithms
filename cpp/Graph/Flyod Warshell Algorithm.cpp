#include <bits/stdc++.h>
using namespace std;

void floydWarshell(vector<vector<int>> &adjMat, int V) {
    vector<vector<int>> distance(adjMat);
    vector<vector<int>> path(V, vector<int>(V, -1));
    
    // initialize the distance between vertex i to i as zero
    for(int i=0; i<V; i++) distance[i][i] = 0;

    for(int k=0; k<V; k++) {
        /*
            k is used for via vertex....
            in each iteration we are finding the distance between vertex i and 
            vertex j via vertex k
        */
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                /*
                    To avoid overflow, check the edge case...
                    if any of the value is INT_MAX then adding any number will result
                    into overflow
                */
                if(distance[i][k] == INT_MAX || distance[k][j] == INT_MAX)
                    continue;
                if(distance[i][j] > distance[i][k] + distance[k][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];                                        
                }
            }
        }
    }
    
    for(int i=0; i<V; i++) {
        if(distance[i][i] < 0) {
            cout << "Negative edge cycle exist in the graph";
            return;
        }
    }

    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            if(distance[i][j] == INT_MAX) cout << " - ";
            else cout << " " << distance[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    
    vector<vector<int>> adjMat(v, vector<int> (v, INT_MAX));
    for(int i=0; i<e; i++) {
        int u1, u2, w;
        cin >> u1 >> u2 >> w;
        
        adjMat[u1][u2] = w;
    }
    
    floydWarshell(adjMat, v);
}
