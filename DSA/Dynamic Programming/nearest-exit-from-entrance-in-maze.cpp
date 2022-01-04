// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

class Solution {
public:
    int bfs(vector<vector<char>> &maze, int sr, int sc) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        
        int moves = 0;
        maze[sr][sc] = '+';
        q.push({sr, sc});
        
        while(!q.empty()) {
            int n1 = q.size();
            moves++;
            
            while(n1--) {
                auto [r, c] = q.front();
                q.pop();
                
                int dir[][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
                // adjacent directions
                for(int i=0; i<4; i++) {                    
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];

                    if(nr < 0 || nr >= m || nc < 0 || nc >= n || maze[nr][nc] == '+') 
                        continue;
                    
                    if(nr == 0 || nc == 0 || nr == m-1 || nc == n-1) {
                        if(nr != sr || nc != sc) return moves;   
                    }
                    
                    maze[nr][nc] = '+';
                    q.push({nr, nc});
                }
            }
        }
        
        return -1;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        
        return bfs(maze, entrance[0], entrance[1]);
    }
};