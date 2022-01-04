/* Time Complexity: O(sorting + union-find) = O(E*LogE + E*LogV) = O(E*LogE) = O(E*LogV) */
#include <bits/stdc++.h>
using namespace std;

int findParent(int node, vector<int> &parent) {
  if(parent[node] == -1) return node;

  return parent[node] = findParent(parent[node]);
}

bool doUnion(int node1, int node2, vector<int> &parent, vector<int> &rank) {
  int parent1 = findParent(node1, parent);
  int parent2 = findParent(node2, parent);

  if(parent1 == parent2) return false;

  if(rank[parent1] < rank[parent2]) 
    parent[parent1] = parent2;
  else if(rank[parent1] > rank[parent2]) 
    parent[parent2] = parent1;
  else {
    parent[parent2] = parent1;
    rank[parent1]++;
  }

  return true; 
}

vector<pair<int, int>> kruskal(vector<pair<int, int>> adjList[], int V) {
  vector<vector<int>> tempList;
  
  for(int u=0; u<V; u++) {
    for(pair<int, int> e : adjList[u]) {
      tempList.push_back({ e.second, u, e.first });
    }
  }

  sort(tempList.begin(), tempList.end(), [](vector<int> &v1, vector<int> &v2){
    return v1[0] < v2[0];
  });

  vector<int> parent(V, -1);
  vector<int> rank(V, 0);
  vector<vector<int>> mst;

  for(int i=0; i<tempList.size(); i++) {
    int w = tempList[i][0], u = tempList[i][1], v = tempList[i][2];

    /* If u and v belong to different component then do union and save in mst otherwise avoid */
    if(doUnion(u, v, parent, rank)) {
      mst.push_back({ u, v, w });
    }
  }

  return mst;
}

int main() {
  int v, e;
  cin >> v >> e;

  vector<pair<int, int>> adjList[v];
  for(int i=0; i<e; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adjList[u].push_back({ v, w });
    adjList[v].push_back({ u, w });
  }

  vector<vector<int>> mst(kruskal(adjList, v));
  for(int i=0; i<mst.size(); i++) {
    cout << mst[i][0] << " " << mst[i][1] << " " << mst[i][2] << endl;
  }
}

/* 
6 9
0 1 2
0 3 1
0 4 4
1 2 3
1 5 7
2 5 8
2 3 5
4 3 9
*/