#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> PII; /*(cost to reach vertex v, vertex v)*/

vector<int> getPrimsMST(vector<PII> adj[], int v) {
    priority_queue<PII, vector<PII> , greater<PII> > q;
    vector<int> mst;
    vector<int> includedVertex(v, false);
    int cost = 0;
    
    q.push(make_pair(0, 0));
    // includedVertex[0] = true;
    
    while(!q.empty()) {
        PII p = q.top();
        q.pop();
        
        if(includedVertex[p.second]) continue;
        includedVertex[p.second] = true;
        cost += p.first;
        mst.push_back(p.second);
        
        for(PII u : adj[p.second]) {
            if(!includedVertex[u.second])
                q.push(u);
        }
    }
    
    return mst;
}

int main() {
    int e, v;
    cin >> v >> e;
    
    vector<PII> adj[v];
    for(int i=0; i<e; i++) {
        int u1, u2, w;
        cin >> u1 >> u2 >> w;
        
        adj[u1].push_back(make_pair(w, u2));
        adj[u2].push_back(make_pair(w, u1));
    }

    vector<int> primsMST;
    primsMST = getPrimsMST(adj, v);
    for(int i=0; i<primsMST.size(); i++) cout << primsMST[i] << " ";
    cout << endl;
    
    return 0;
}
