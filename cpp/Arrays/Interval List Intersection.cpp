class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0, j = 0;
        vector<vector<int> > ans;
        
        for(; i<firstList.size() && j<secondList.size(); ) {
            int x1 = firstList[i][0];
            int y1 = firstList[i][1];
            int x2 = secondList[j][0], y2 = secondList[j][1];
            
            if(x1 < x2) {
                if(y1 < x2) i++;
                else {
                    if(y1 < y2) {
                        ans.push_back(vector<int> ({x2, y1}));
                        i++;
                    } else {
                        ans.push_back({x2, y2});
                        j++;
                    }
                }
            } else {
                if(x1 <= y2) {
                    if(y1 <= y2) {
                        ans.push_back(vector<int> ({x1, y1}));
                        i++;
                    } else {
                        ans.push_back(vector<int> ({x1, y2}));
                        j++;
                    }
                } else {
                    j++;
                }
            }
        }
        
        return ans;
    }
};


// Refracted Code
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size(); 
        int m = secondList.size();
        vector<vector<int> > ans;
        
        int i = 0, j = 0;
        
        while(i < n && j < m) {
            if(firstList[i][1] >= secondList[j][0] and firstList[i][0] <= secondList[j][1]) {
                int low = max(firstList[i][0], secondList[j][0]);
                int high = min(firstList[i][1], secondList[j][1]);
                
                ans.push_back({low, high});
            }
            
            firstList[i][1] < secondList[j][1] ? i++ : j++;
        }
        
        return ans;
    }
};
