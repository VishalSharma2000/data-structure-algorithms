/*
  Problem Statment: We have 4 concentric circular locks having numbers written on them from 0 to 9 in circular manner. We can move the circular lock in any direction and the edges number are circular meaning 0 will to go to 9 and 9 will go to 0.

  We are initially at the position 0000 where each ith place value represent the state of the ith clock. We are given a target state and deadends state.
  Deadends states are those states where the lock will not be able to move further...it will get self lock and hence you cannot proceed with any move

  So, we have to find minium number of steps required to reach the target state from the initial state

  Thinking approach :
    Remember the Unique Path II problem - Its almost the same problem...don't think that in the unique path 2(further i will say it UP) problem we had to find all the UP and here we have to find path with minimum cost...Notice that we don't have any cost to go from one state to another...we will just add 1 to go to next node and that is same as finding path length....The point I want to bring in notice here is see in UP problem we had to go from (0, 0) to (m-1, n-1) thinking that the size of the grid is (m, n) and here also we have to go from "0000" to some target...

    So, we can make a 4d array and with the help of dp we can get the minium path length distance...but this will not work bcoz here the grid is circular its not ending anywhere - we can go from 0 to 9 and 9 to 0 - so there will not be any direction change and hence you will stack overflow for the recurive solution

  So, we have made the use of graph 
  I have also learned the the below concept from this problem...
  If in the question we are given something called state asin changing from this state to that state then only two things should come in your mind 
  1) DP                 2) Graph 

  If we think properly we will notice that graph is basically made of states where each node is state end and the edges are used to go from one state to another. If you have learned automata anytime you will be able to relate much faster...

  So, here each valid lock position is one state and from each state we have 8 different state positions to go on....
  So, while making the edge between any two state we will check if the state is deadend or not (deadend state is like dead state in automata and a node in graph which has 0 out degree)

  So, once the graph is made we can make use of normal bfs to find the shortest path
*/
class Solution {
public:
    vector<string> getDirs(string curr) {
        vector<string> res;
        
        /* We will have 8 direction to from one state */
        /* Suppose w = curr[3], x = curr[2], y = curr[1], z = curr[0] 
          (w+1, x, y, z) , (w-1, x, y, z)
          (w, x+1, y, z) , (w, x-1, y, z)
          (w, x, y+1, z) , (w, x, y-1, z)
          (w, x, y, z+1) , (w, x, y, z-1)
        */
        for(int i=0; i<4; i++) {
            string temp = curr;
            
            temp[i] = ((curr[i] - '0') + 1) % 10 + '0';
            /* (curr[i] - '0') => char to no 
                + 1  => no + 1 
                %10 will give nos <- 9 => mod bcoz need less than equal 9 => 
                + '0'  => again to char 
            */
            res.push_back(temp);
            
            temp[i] = ((curr[i] - '0') - 1 + 10) % 10 + '0';
            
            res.push_back(temp);
        }
        
        return res;
    }
    
    int openLock(vector<string>& deadends, string target) {
        /* For finding the state is deadstate or not...we have used unordered_set bcoz find operation is O(1) 
        while in vector it would be O(N) in worst case where N = 10000 */
        unordered_set<string> de(deadends.begin(), deadends.end());
        
        /* To keep track of visited nodes */
        map<string, bool> visited;
        /* BFS Queue */
        queue<string> q;
        
        if(de.find("0000") != de.end()) return -1;
        if(target == "0000") return 0;
        visited["0000"] = true;
        q.push("0000");
        int dist = 0;
        
        /* Normal BFS way to find the shortest path of unweighted graph */
        while(!q.empty()) {
            int size = q.size();
            dist++;
            
            for(int i=0; i<size; i++) {
                string curr = q.front(); q.pop();
                
                vector<string> dirs(getDirs(curr));
                for(string dir : dirs) {
                    if(dir == target) return dist;
                    
                    /* If unvisited and not available in deadends */
                    if(!visited[dir] && de.find(dir) == de.end()) {
                        q.push(dir);
                        visited[dir] = true;
                    }
                }
            }
        }
        
        return dist;
    }
};