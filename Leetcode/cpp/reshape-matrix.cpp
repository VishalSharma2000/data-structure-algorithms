class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        if(m*n != r*c) {
            return mat;
        }
        
        vector<int> temp;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                temp.push_back(mat[i][j]);
            }
        }
        
        vector<vector<int>> ans(r, vector<int>(c));
        int k = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                ans[i][j] = temp[k++];
            }
        }
        
        return ans;
    }
};

/* Row First Approach */
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
         int m = mat.size(), n = mat[0].size();
        
        // if number of cells are not same
        if(r*c != m*n) return mat;
  
        vector<vector<int>> ans(r, vector<int>(c));
        for(int i=0; i<m*n; i++) {
            ans[i/c][i%c] = mat[i/n][i%n];
        }
        
        return ans;
    }
};

/* Column First Approach */
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
         int m = mat.size(), n = mat[0].size();
        
        // if number of cells are not same
        if(r*c != m*n) return mat;
  
        vector<vector<int>> ans(r, vector<int>(c));
        for(int col=0; col<n; col++) {
            for(int row=0; row<m; row++) {
                int new_row = (row * n + col) / c;
                int new_col = (row * n + col) % c;
                
                ans[new_row][new_col] = mat[row][col];
            }
        }
        
        return ans;
    }
};

/* Another Approach */
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
       // cout<<m<<" "<<n<<" "<<r<<" "<<c<<endl;
        if(m*n!=r*c)
        {
            return mat;
        }
        vector<vector<int>>ans(r,vector<int>(c));
        int l=0,h=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int a=mat[i][j];
                //cout<<a<<endl;
                ans[l][h]=a;
               // cout<<l<<" "<<h<<" "<<a<<endl;
                h++;
                if(h==c)
                {
                    l++;
                    h=0;
                }
            }
        }
        return ans;
    }
};