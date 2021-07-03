class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int> > temp;
        
        for(int i=0; i<(int) arr.size(); i++) {
            temp.push_back({arr[i], abs(arr[i] - x)});
        }
        
        sort(temp.begin(), temp.end(), [](pair<int, int> &p1, pair<int, int> &p2) {
            if(p1.second == p2.second) return p1.first < p2.first;
            return p1.second < p2.second;
        });
        
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(temp[i].first);
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

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
