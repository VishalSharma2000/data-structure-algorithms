class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return {};
        
        int n = matrix[0].size();
        
        vector<int> ans;
        int x = -1, y = 0;
        for(int i=0; i<(m+n-1); i++) {
            if(i%2 == 0) {
                x++;
                int sum = x + y;
                
                while(x >=0 && y < n && (x + y) == sum) {
                    if(x < m && y >= 0)
                        ans.push_back(matrix[x][y]);
                    
                    x--;
                    y++;
                }
                x++;
                y--;
            } else {
                y++;
                int sum = x + y;
                
                while(x < m && y >= 0 && (x+y == sum)) {
                    if(x >= 0 && y < n)
                        ans.push_back(matrix[x][y]);
                    
                    x++;
                    y--;
                }
                x--;
                y++;
            }
        }
        
        return ans;
    }
    
    
};
