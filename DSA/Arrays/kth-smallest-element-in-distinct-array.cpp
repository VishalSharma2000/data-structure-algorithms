/* Given an array of size n with distinct elements, we have to find kth smallest element in the array */

/* Here we are doing Quick Sort, which is basically an optimization of sorting approach(Time Complexity: O(NLogN)) so here the main idea is to sort the array only till kth position and whenever we encounter a pivot at (k-1)th position then we can return the element at that position */
/* This method will work only when the array elements are distinct bcoz in this case we are assured that the kth smallest element will be at (k-1)th index of the array but if the array elements are not distinct then this approach will give wrong answer */

/* We can also use randomized quick select. In randomized quick select worst case time complexity will be still O(N^2) and average case
time complexity will O(N). We say that randomized quick select works better than normal quick select because the probability of getting
a number from 0 to 9 is same to there is more chance that the array will be divided into two halves */

/* Worst Case Linear Time */
/* https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/ */

/* Time Complexity: O(N) for average cases and O(N^2) for worst cases */

int partition(vector<int> &arr, int l, int h) {
    /* Here last value is taken as pivot and i is taken for pointing to the next place where smaller number can be inserted */
    int pivot = arr[h];
    int i = l;
    
    for(int j=l; j<=h-1; j++) {
      // if val smaller than pivot is found the swap the numbers
        if(arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    
    // bring the pivot value to it's correct position
    swap(arr[h], arr[i]);
    return i;
}

int kthSmallestElement(vector<int> &arr, int l, int h, int k) {
    // k should be more than 1 and less then or equal to n(size of the array)
    if(k > 0 && k <= h-l+1) {
        // pos => is the position of the element which is been placed at it's correct position
        int pos = partition(arr, l, h);
        
        if(pos-l == k-1) return arr[pos];
        // if obtained position is more than the kth position then do recursion for left side
        else if(pos-l > k-1)
            return kthSmallestElement(arr, l, pos-1, k);
        
        // do recursion for right side
        return kthSmallestElement(arr, pos+1, h, k-(pos-l+1));
        /* note that here we are also changing the required kth value here, 
        here all the values from l to pos will be first (pos-l+1) smallest element so when we are calling for right side we are 
        removing all this elements from the count */
    }
    
    return INT_MAX;
}

int main() {
    vector<int> arr{12, 3, 5, 7, 4, 19, 26};
    int k = 5;
    
    int kthSmallest = kthSmallestElement(arr, 0, arr.size()-1, k);
    if(kthSmallest == INT_MAX) cout << "Kth smallest does not exist" << endl;
    else cout << kthSmallest << endl;
}


/* USING STL MAP */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int, int, greater<int>> mp;
        
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        int i = 0;
        for(auto it=mp.begin(); it!=mp.end(); it++) {
            i += it->second;
            
            if(i >= k) return it->first;
        }
        
        return INT_MAX;
    }
};