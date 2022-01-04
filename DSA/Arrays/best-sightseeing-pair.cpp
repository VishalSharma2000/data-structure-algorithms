/* https://leetcode.com/problems/best-sightseeing-pair/ */

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        
        vector<int> p(n), m(n);
        for(int i=0; i<n; i++) {
            p[i] = values[i] + i;
            m[i] = values[i] - i;
        }
        
        vector<int> maxV(n);
        maxV[0] = p[0];
        for(int i=1; i<n; i++) {
            maxV[i] = max(maxV[i-1], p[i]);
        }
        
        int maxVal = INT_MIN;
        for(int i=n-1; i>=1; i--) {
            int sum = m[i] + maxV[i-1];
            
            if(sum > maxVal) maxVal = sum;
        }
        
        return maxVal;
    }
};