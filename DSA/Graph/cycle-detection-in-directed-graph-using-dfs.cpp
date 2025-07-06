/* Normal dfs cannot be used to detect cycle in directed graph bcoz their may be one or more paths to reach a particular node.
  But if we are able to reach the node from two different paths then that does not mean that the cycle has a graph. 
  Hence to overcome this issue we will have to maintain an extra currentDFS array to keep track of all the elements in the currentDFS
  
  There is a cycle in the graph only if a already visited node is again found in the recursion but in the same dfs recusion stack.  */

/* Time complexity: O(N+E), Space Complexity: O(2N) */
bool isCyclePresentDFS(vector<int> adj[], int node, vector<bool> &visited, vector<bool> &currDFS) {
  visited[node] = true;
  currDFS[node] = true;

  for(int v : adj[node]) {
    if(!visited[v]) {
      if(isCyclePresentDFS(adj, v, visited, currDFS)) return true;
    } else if(visited[v] && currDFS[v]) return true;
  }

  currDFS[node] = false;
  return false;
}

bool isCyclePresent(vector<int> adj[], int V) {
  vector<bool> visited(V+1, false);
  vector<bool> currDFS(V+1, false);

  /* Doing for all the components */
  for(int i=1; i<=V; i++) {
    if(!visited[i]) {
      if(isCyclePresentDFS(adj, i, visited, currDFS)) return true;
    }
  }

  return false;
}
