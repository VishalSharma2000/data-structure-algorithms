// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

/* DFS Approach */
class Solution {
public:
    void dfs(vector<int> adjList[], int node, vector<bool> &visited) {
        visited[node] = true;
        for(int u : adjList[node]) {
            if(!visited[u]) {
                dfs(adjList, u, visited);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
       if(connections.size() < n-1) return -1;
        
        int components = 0;
        vector<int> adjList[n];
        
        for(int i=0; i<connections.size(); i++) {
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(adjList, i, visited);
                components++;
            }
        }
        
        return components-1;
    }
};

/* Union Find Approach */
class Solution {
public:
    int findParent(int node, vector<int> &parent) {
        if(parent[node] == node) return node;
        
        return parent[node] = findParent(parent[node], parent);
    }
    
    void doUnion(int node1, int node2, vector<int> &rank, vector<int> &parent) {
        if(rank[node1] > rank[node2]) {
            parent[node2] = node1;
        } else if(rank[node1] < rank[node2]) {
            parent[node1] = node2;
        } else {
            parent[node2] = node1;
            node1++;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        
        vector<int> parent(n);
        vector<int> rank(n, 0);
        
        for(int i=0; i<n; i++) parent[i] = i;
        
        for(int i=0; i<connections.size(); i++) {
            int parent1 = findParent(connections[i][0], parent);
            int parent2 = findParent(connections[i][1], parent);
            
            if(parent1 != parent2) {
                doUnion(parent1, parent2, rank, parent);
            }
        }
        
        int ans =0;
        for(int i=0; i<n; i++)
            if(parent[i] == i) 
                ans++;
        
        return ans-1;
    }
};