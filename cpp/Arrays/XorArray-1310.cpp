class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // first find the prefix array by taking xor from [0...i]
        vector<int> prefix(arr.size(), 0);
        prefix[0] = arr[0];
        
        for(int i=1; i<prefix.size(); i++) 
            prefix[i] = prefix[i-1] ^ arr[i];
        
        /* now we are going to find xor with the relation
         xor[a, b] = xor[0, a-1] ^ xor[0, b]
         here x[0, b] = x[0] ^ x[1] ^ ... ^ x[b]
         and x[0, a-1] = x[0] ^ x[1] ^ .. ^ x[a-1]
         
         since xor is inverse of itself
         x[0, a-1] ^ x[0, b] will remove all the elements from [0, a-1]
         hence we will get the xor of values from [a, b]
        */
        
        vector<int> ans;
        for(auto q : queries) 
            ans.push_back(q[0] > 0 ? prefix[q[0]-1] ^ prefix[q[1]] : prefix[q[1]]);
        
        return ans;
    }
};

Time complexity: O(n)
Space complexity: O(n) for prefix array, if we are using another vector for storing it otherwise O(1)
