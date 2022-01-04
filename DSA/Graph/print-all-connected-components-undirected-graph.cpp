/* Connected Graph: A graph is said to be connected graph when there is path to reach every vertex from every other vertex */
/* Print all the connected components of the graph in undirected graph */
/* Normal BFS and DFS will only work when the graph is undirected because if there is an edge between u and v
then we can traverse from u to v and v to u. But if the graph is directed doing this would need two edges. In
directed graph we usually find strongly connected subgraph using kosajaru or tarjan algorithm to find strongly connected components */

/* Example:
  0 --- 1 --- 2 => undirected and connected graph bcoz we can reach every node from every other node
  so doing normal bfs and dfs would work properly

  0 ---> 1 ---> 2 => directed but not connected graph bcoz we can't reach from every node to every other node
  so doing normal dfs and bfs will give the graph is connected bcoz all the nodes will be visited in one dfs and one bfs 
  traversal but it's actually not connected. So, here we can find strongly connected components using kosajaru and tarjan 
  algorithms
 */

#include <bits/stdc++.h>
using namespace std;

/* Time Complexity: O(V + E), Space Complexity: O(V + E) - CallStack */
/* It's actually normal dfs or bfs, just we have added a cout statement to print the nodes */

/* With DFS */
void dfsUtil(vector<int> adj[], int u, vector<bool> &visited) {
  cout << u << " ";     // extra cout to just print the node

  visited[u] = true;
  for(int v : adj[u]) {
    if(!visited[v])
      dfsUtil(adj, v, visited);
  }
}

void printAllConnectedComponentsUsingDFS(vector<int> adj[], int V) {
  /* Do Normal DFS for all unvisited nodes */

  vector<bool> visited(V, false);

  for(int i=0; i<V; i++) {
    if(!visited[i]) {
      cout << endl; // extra cout for printing all connected components node on new line
      dfsUtil(adj, i, visited);
    }
  }
}

/* With BFS */
/* Time Complexity: O(V + E), Space Complexity: O(V + E) */
void bfsUtil(vector<int> adj[], int src, vector<bool> &visited) {
  queue<int> q;

  visited[src] = true;
  q.push(src);

  while(!q.empty()) {
    int u = q.front();
    q.pop();
    cout << u << " ";

    for(int v : adj[u]) {
      if(!visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
  }
}

void printAllConnectedComponentsUsingBFS(vector<int> adj[], int V) {
  vector<bool> visited(V, false);

  for(int i=0; i<V; i++) {
    if(!visited[i]) {
      cout << endl;
      bfsUtil(adj, i, visited);
    }
  }
}

int main() {
  int V, E;
  cin >> V >> E;

  vector<int> adj[V];
  for(int i=0; i<E; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  printAllConnectedComponentsUsingDFS(adj, V);
  printAllConnectedComponentsUsingBFS(adj, V);
}