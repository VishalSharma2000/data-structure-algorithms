/*
  Graph is DAG(Directed Acyclic Graph)

  Main Idea: consider a neigbour once and don't consider once. 
  idea: from power set question
*/

class Solution {
public:
    void util(vector<vector<int> > &graph, int node, vector<int> &path, vector<vector<int> > &ans) {
        if(node == graph.size()-1) {
            ans.push_back(path);
            return;
        }

        for(int temp = 0; temp < graph[node].size(); temp++) {
            path.push_back(graph[node][temp]);
            util(graph, graph[node][temp], path, ans);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > ans;
        int node = 0;
        vector<int> path;
        path.push_back(0);

        util(graph, node, path, ans);
        return ans;
    }
};