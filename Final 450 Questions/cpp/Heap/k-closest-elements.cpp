class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> maxHeap;
        
        for(int i=0; i<arr.size(); i++) {
            maxHeap.push(make_pair(abs(x-arr[i]), arr[i]));
            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        vector<int> ans(maxHeap.size());
        int m = ans.size()-1;
        while(!maxHeap.empty()) {
            ans[m--] = maxHeap.top().second;
            maxHeap.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};