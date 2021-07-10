/* Detect cycle using DFS and BFS */
/* It's normal DFS or BFS traversal, just that we have to see that if the already visited node is repeated. If
the already visited node is repeated then there is cycle in graph otherwise no cycle */

/* Time Complexity: O(E + V), Space Complexity: O(V+E + V):(callstack + visitedarray) */

/* DFS Method */
bool DFSUtil(vector<int> adj[], int node, int prevNode, vector<bool> &visited) {
  visited[node] = true;

  for(int u : adj[node]) {
    if(!visited[u]) {
      /* If the adjancent node is not visited then again call for cycle detection */
      if(DFSUtil(adj, u, node, visited)) return true;
    } else if(u != parent) return true;
    /* If the adjacent node is already visited and its not equal to previously visited node then definately it was 
    visited by some node in past. This shows that cycle exist */
  }

  return false;
}

/* Time Complexity: O(E + V), Space Complexity: O(V+E + V):(callstack + visitedarray) */

/* BFS Method */
bool BFSUtil(vector<int> adj[], int node, int prevNode, vector<bool> &visited) {
  queue<pair<int, int>> q;

  /* Start with making the source node or starting node visited and push in queue */
  visited[node] = true;
  q.push({node, prevNode});

  while(!q.empty()) {
    int u = q.front().first;
    int prevNode = q.front().second;
    q.pop();

    for(int v : adj[u]) {
      /* If the adjacent node is not visited, then visit and push in queue else 
      if visited and not equal to last node then there is cycle */
      if(!visited[v]) {
        visited[v] = true;
        q.push({v, u});
      } else if(v == prevNode) continue;
      else if(v != prevNode) return true;
    }
  }

  return false;
}

bool checkCycleUsingDFS(vector<int> adj[], int V) {
  vector<bool> visited(V+1, false);

  /* Here we are assuming that the graph may be connected or not connected. So to handle the case where graph may not 
  be connected we are using a for loop otherwise we would have directly started bfs or dfs from any node */
  /* 1-based Indexing */
  for(int i=1; i<=n; i++) {
    if(!visited[i]) {
      /* We need a extra argument to keep track of the previous node traversed otherwise the previous node will always be visited.
      So to differentiate between previously visited node and other nodes we are keeping track of the previously visited node */
      if(DFSUtil(adj, i, -1, visited)) return true;
    }
  }

  return false;
}

