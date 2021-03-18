class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        
        vector<vector<int> > heights(m, vector<int> (n));
        queue<pair<int, int> > q;
        for(int r=0; r<m; r++) {
            for(int c=0; c<n; c++) {
                if(isWater[r][c] == 1) {
                    heights[r][c] = 0;
                    q.push(make_pair(r, c));
                } else 
                    heights[r][c] = -1;
            }
        }
        
        int DIR[] = {0, 1, 0, -1, 0};
        while(!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            
            int r = temp.first;
            int c = temp.second;
            
            for(int i=0; i<4; i++) {
                int nr = r + DIR[i];
                int nc = c + DIR[i+1];
                
                if(nr >= m || nr < 0 || nc < 0 || nc >= n || heights[nr][nc] != -1) continue;
                
                heights[nr][nc] = heights[r][c] + 1;
                q.push(make_pair(nr, nc));
            }
        }
        
        return heights;
    }
};
