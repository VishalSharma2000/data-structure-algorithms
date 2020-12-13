class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> freq1, freq2;
        unordered_set<int> nos;
        vector<int> ans;
        
        for(int i=0; i<nums1.size(); i++) {freq1[nums1[i]]++; nos.insert(nums1[i]);}
        for(int i=0; i<nums2.size(); i++) {freq2[nums2[i]]++;}
        
        for(auto it=nos.begin(); it!=nos.end(); it++) {
            int val = min(freq1[*it], freq2[*it]);
            
            while(val--) ans.push_back(*it);
            
            // O(n) approach
            // if all the elements of array 1 is same then 
            // outer for loop will run only once and inner while loop will run n times
            // and in other case if all the elements are different
            // then outer for loop runs n times and inner while loop runs 1 times for each.
        }
        
        return ans;
    }
};


// approach if both the array are sorted 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> ans;
        int p1 = 0, p2 = 0;
        while(p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] < nums2[p2]) p1++;
            else if(nums1[p1] > nums2[p2]) p2++;
            else {
                ans.push_back(nums1[p1]);
                p1++;
                p2++;
            }
        }
        
        return ans;
    }
};