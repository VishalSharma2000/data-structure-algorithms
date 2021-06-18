class Graph {
  public:
    bool checkCycleUtil(vector<int> adj[], int node, int prevNode, vector<bool> &visited) {
      visited[node] = true;

      for(int u : adj[node]) {
        if(!visited[u]) {
          /* If the adjancent node is not visited then again call for cycle detection */
          if(checkCycleUtil(adj, u, node, visited)) return true;
        } else if(u != parent) return true;
        /* If the adjacent node is already visited and its not equal to previously visited node then definately it was 
        visited by some node in past. This shows that cycle exist */
      }

      return false;
    }

    bool checkCycle(vector<int> adj[], int V) {
      vector<bool> visited(V+1, false);

      /* Check for all components */
      /* 1-based Indexing */
      for(int i=1; i<=n; i++) {
        if(!visited[i]) {
          /* We need a extra argument to keep track of the previous node traversed because if the previous node will always be visited.
          So to differentiate between previously visited node and other nodes we are keeping track of the previously visited node */
          if(checkCycleUtil(adj, i, -1, visited)) return true;
        }
      }

      return false;
    }
};