#include <bits/stdc++.h>
using namespace std;

/* 
  Time Complexity for normal union find (without rank and path compression) => O(n) in worst case
  Time Complexity when operation uses rank => O(Logn)
  Time Complexity when operation uses both rank and path compression => O(4 * alpha) => O(1)
*/

class UnionFind {
  private:
    vector<int> parent;
    vector<int> rank;
    int n;

  public:
    UnionFind(int n) {
      this->n = n;
    }

    void makeSet() {
      parent.resize(n);
      for(int i=0; i<n; i++) parent.push_back(i);

      rank.resize(n);
      fill(rank.begin(), rank.end(), 0);
    }

    int findParent(int node) {
      if(parent[node] == node) return node;

      return parent[node] = findParent(parent[node]);
    }

    void doUnion(int node1, int node2) {
      int parent1 = findParent(node1);
      int parent2 = findParent(node2);

      if(parent1 == parent2) {
        cout << "Both node belong to same component" << endl;
        return;
      }

      if(rank[parent1] > rank[parent2]) {
        parent[parent2] = parent1;
      } else if(rank[parent1] < rank[parent2]) {
        parent[parent1] = parent2;
      } else {
          parent[parent1] = parent2;
          rank[parent2]++;
      }
    }

    void printRank() {
      for(int i=0; i<n; i++) {
        cout << i << " " << rank[i] << endl;
      }
    }

    void printParent() {
      for(int i=0; i<n; i++) {
        cout << i << " " << parent[i] << endl;
      }
    }
};

int main() {
  int v; cin >> v;
  UnionFind uf = UnionFind(v);
  uf.makeSet();

  uf.printRank();
  uf.printParent();

  uf.doUnion(0, 1);
  uf.doUnion(1, 2);
  uf.doUnion(3, 4);
  uf.doUnion(1, 3);

  uf.printParent();
  uf.printRank();
}