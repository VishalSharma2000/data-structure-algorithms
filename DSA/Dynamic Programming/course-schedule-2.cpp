/* LeetCode Question: https://leetcode.com/problems/course-schedule-ii/ */
/* We have n courses numbered from 0 to n-1. We also have a prerequisite array, each element is of the form [a, b] which
indicates that to take the course a the pre-requisite is the course b. So, basically we have to finish the course b before
we can start the course a. If there is a way to complete all the courses then we have to return the order otherwise empty 
vector */

/* Intution: The graph would have edge like a-> b, means to go and do the course b we first have to complete or visit the course a.
So, here we have to find the ordering of the nodes such that all the further nodes or child nodes will come after the parent node
which can be done using topological sort  */

/* Time Complexity: O((E + V) + V) {one for topo sort and order for cycle detection} */
/* Space Complexity: O(E + E + V) { for storing adjacency list, recursion stack and topo sort } */
class Solution {
public:
    void dfs(vector<int> adj[], int node, vector<bool> &visited, stack<int> &s) {
        visited[node] = true;
        
        for(int v : adj[node]) {
            if(!visited[v])
                dfs(adj, v, visited, s);
        }
        
        /* After we have finished visiting all further nodes, now all the further nodes are in stack. Hence, we can push 
        this node into the stack */
        s.push(node);
    }
    
    vector<int> getTopologicalSort(vector<int> adj[], int nC) {
        stack<int> s;
        vector<bool> visited(nC, false);
        
        /* Normal DFS call for all the nodes */
        for(int i=0; i<nC; i++) {
            if(!visited[i])
                dfs(adj, i, visited, s);
        }
        
        /* Pop all elements from stack to get topo sort */
        vector<int> topoSort;
        while(!s.empty()) {
            topoSort.push_back(s.top());
            s.pop();
        }
        
        return topoSort;
    }
    
    bool checkCycleExist(vector<int> adj[], int V, vector<int> &topoSort) {
        unordered_map<int, int> pos;
        
        for(int i=0; i<topoSort.size(); i++) {
            pos[topoSort[i]] = i;
        }
        
        for(int i=0; i<V; i++) {
            for(int v : adj[i]) {
                if(pos[v] < pos[i]) return true;
            }
        }
        
        return false;
    }
    
    vector<int> findOrder(int nC, vector<vector<int>>& pre) {
        vector<int> adj[nC];
        
        /* Making a directed graph adjacency list */
        for(int i=0; i<pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        vector<int> topo(getTopologicalSort(adj, nC));
        if(checkCycleExist(adj, nC, topo)) return {};
        
        return topo;
    }
};

/* Checking if the cycle exist or not simultanously while finding topological sort */
/* Approach : Have used the general way to find cycle in directed graph i.e. by tracing the nodes in current DFS call */
class Solution {
public:
    bool dfs(vector<int> adj[], int node, vector<bool> &visited, vector<bool> &currDFS, stack<int> &s) {
        visited[node] = true;
        currDFS[node] = true;
        
        for(int v : adj[node]) {
            if(!visited[v]) {
                if(!dfs(adj, v, visited, currDFS, s)) return false;   
            } else if(currDFS[v]) return false;
        }
        
        currDFS[node] = false;
        s.push(node);
        return true;
    }
    
    vector<int> getCourseOrder(vector<int> adj[], int nC) {
        stack<int> s;
        vector<bool> visited(nC, false);
        vector<bool> currDFS(nC, false);
        
        for(int i=0; i<nC; i++) {
            if(!visited[i]) {
                if(!dfs(adj, i, visited, currDFS, s)) return {};
            }
        }
        
        vector<int> topoSort;
        while(!s.empty()) {
            topoSort.push_back(s.top());
            s.pop();
        }
        
        return topoSort;
    }
    
    vector<int> findOrder(int nC, vector<vector<int>>& pre) {
        vector<int> adj[nC];
        
        for(int i=0; i<pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        vector<int> topo(getCourseOrder(adj, nC));
        
        return topo;
    }
};

/* Approach: Kahn's Algorithm */
/* TC: O(E + V+E) { for creatin adj list, traversing over all vector and edges }, 
  SC: O(V+E + V + V + V) { Adjacency List, indegree-vector, queue, order } */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<int> adj[numCourses];
        
        for(int i=0; i<prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            
            indegree[prerequisites[i][0]]++;
        }
        
        int doneCnt = 0;    // to keep track of number of nodes completed
        queue<int> q;
        
        /* Push all courses or nodes with indegree 0, means this course has no other prerequisite course */
        for(int i=0; i<indegree.size(); i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> order;
        while(!q.empty()) {
            int v = q.front();
            q.pop();

            doneCnt++; // incremenet complete count
            order.push_back(v); 
            
            /* Decrease indegree for all adjacent node of v */
            for(int u : adj[v]) {
                indegree[u]--;
                
                if(indegree[u] == 0) q.push(u);
            }
        }
        
        /* If all the nodes are traversed then order is correct otherwise graph has a cycle */
        return doneCnt == numCourses ? order : vector<int> {};
    }
};