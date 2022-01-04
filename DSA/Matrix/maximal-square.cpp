class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        int n = m.size();
        int m1 = m[0].size();
        int maxSq = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m1; j++) {
                if(m[i][j] == '1') {
                    int r = i, c = j;
                    bool status = true;
                    while(r-1 >= 0 && c+1 < m1 && status) {
                        r -= 1;
                        c += 1;
                        
                        if(m[r][c] == '0') {
                            status = false;
                            break;
                        }
                        
                        int k = c;
                        while(--k >= j) {
                            if(m[r][k] == '0') {
                                status = false;
                                break;
                            }   
                        }
                        
                        k = r;
                        while(++k <= i) {
                            if(m[k][c] == '0') {
                                status = false;
                                break;
                            }
                        }
                    }
                    
                    if(status)
                        maxSq = max(maxSq, abs(i-r+1));
                    else 
                        maxSq = max(maxSq, abs(i-r));
                    if(maxSq == 3) {
                        cout << i << " " << j << " " << r << " " << endl;
                    }
                }
            }   
        }
        
        return maxSq*maxSq;
    }
};