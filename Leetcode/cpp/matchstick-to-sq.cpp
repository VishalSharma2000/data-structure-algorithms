#include <bits/stdc++.h>
using namespace std;

#define PART 4

bool solve(vector<int> &ms, int i, int sum1, int sum2, int sum3, int sum4, int target) {
        cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << endl;
        if(i == ms.size()) {
            return sum1 == target && sum2 == target && sum3 == target && sum4 && target;
        }
        
        if(sum1 > target || sum2 > target || sum3 > target || sum4 > target) return false;
        
        // if(sum1 == target) done[0] = true;
        // if(sum2 == target) done[1] = true;
        // if(sum3 == target) done[2] = true;
        // if(sum4 == target) done[3] = true;
        
        bool status1 = false, status2 = false, status3 = false, status4 = false;
        
        if((sum1 + ms[i] <= target))
            status1 = status1 || solve(ms, i+1, sum1 + ms[i], sum2, sum3, sum4, target);
        
        if(status1) return status1; 

        if((sum2 + ms[i]) <= target) 
            status2 = status2 || solve(ms, i+1, sum1, sum2 + ms[i], sum3, sum4, target);

        if(status2) return status2;

        if((sum3 + ms[i] <= target))
            status3 = status3 || solve(ms, i+1, sum1, sum2, sum3 + ms[i], sum4, target);
            
        if(status3) return status3;

        if((sum4 + ms[i]) <= target) 
            status4 = status4 || solve(ms, i+1, sum1, sum2, sum3, sum4 + ms[i], target);

        
        // return solve(ms, i+1, sum1 + ms[i], sum2, sum3, sum4, target) ||
        //     solve(ms, i+1, sum1, sum2 + ms[i], sum3, sum4, target) ||
        //     solve(ms, i+1, sum1, sum2, sum3 + ms[i], sum4, target) ||
        //     solve(ms, i+1, sum1, sum2, sum3, sum4 + ms[i], target);
        
        return status1 || status2 || status3 || status4;
}
    
    bool makesquare(vector<int>& ms) {
        int sum = 0;
        int n = ms.size();
        // done.push_back(false);
        // done.push_back(false);
        // done.push_back(false);
        // done.push_back(false);
        
        for(int i=0; i<n; i++) 
            sum += ms[i];
        
        if(sum%PART != 0) return false;
                
        cout << sum/PART << endl;
        return solve(ms, 0, 0, 0, 0, 0, sum/PART);
    }

int main() {
  vector<int> arr{20,13,19,19,4,15,10,5,5,15,14,11,3,20,11};
  cout << makesquare(arr);
}