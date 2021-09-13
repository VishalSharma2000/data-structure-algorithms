/* Leetcode Question: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/ */

/* Given weights of packages which we want to transfer from port 1 to port 2 through the ship. Ship can transfer some packages with some weight
everyday. We have to find the minimum weight capacity of the ship such that all the packages can be transfered from port 1 to port 2 within d days. Packages will be transfered in the order in which they are placed on the conveyor belt */

/* Approach: So, we have to find the value X such that the function f(X) = { is all packages transferable if the weight of the ship is X }. This function also has the property such that if f(X) is true for some value say Y then it will be true for all values from Y+1 to INF. Hence it will be of the format no no no no....yes yes yes yes......Hence we can make use of binary search to solve this question. */

/* Now next hurdle is to find the start and end value and also the condition of when to go left or when to go right.
We know that we would have to atleast transfer one box daily to shift all packages and since weight of the ship can't be change once decided so minimum value of the weight of the ship should be max( all weight packages ) and we can transfer all packages in one day if weight of the ship is sum  of all packages. Hence start = max_element(weight of packages) and end = sum(weight of packages) */

/* Now after getting mid ...we will check that can we transfer all packages with mid as the weight of the ship. If possible we will go to left to find more smaller values of X if not possible then we will go to right to find what value of X satisfies. */

class Solution {
public:
    bool shippable(vector<int> &w, int sw, int days) {
        int i = 0;
        int n = w.size();
        
        while(days > 0) {
            int sum = 0;
            // add packages to ship until weight of added packages becomes more that ship weight capacity (sw)
            while(i<n && sum + w[i] <= sw) {
                sum += w[i];
                i++;
            }
            days--;
        }
        
        // if all packages transfered then return true else false
        return i == w.size();
    }
    
    // TC: O(NLogN)
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        // find max element
        int start = *max_element(weights.begin(), weights.end());
        // find sum of all elements
        int end = accumulate(weights.begin(), weights.end(), 0);
        // we can even assign res = end but let's take INT_MAX
        int res = INT_MAX;
        
        while(start <= end) { // - O(LogN)
            int mid = start + (end - start)/2;
            
            // if true then go left otherwise right - O(N)
            if(shippable(weights, mid, days)) {
                res = mid;
                end = mid-1;
            } else {
                start = mid + 1;
            }
        }
        
        return res;
    }
};