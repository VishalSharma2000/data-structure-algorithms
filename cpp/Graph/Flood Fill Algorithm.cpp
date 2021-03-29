class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int> > q;
        int val = image[sr][sc];
        int n = image.size(), m = image[0].size();
        if(val == newColor) return image;
        
        image[sr][sc] = newColor;
        q.push(make_pair(sr, sc));
        
        while(!q.empty()) {
            pair<int, int> cord = q.front();
            q.pop();
            
            int dir[] = {0, 1, 0, -1, 0};
            for(int i=0; i<4; i++) {
                int nx = cord.first + dir[i];
                int ny = cord.second + dir[i+1];
                
                if(nx < n && ny < m && nx >= 0 && ny >= 0 && image[nx][ny] == val) {
                    image[nx][ny] = newColor;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        
        return image;
    }
};
