class Solution {
public:
    /* TC: O(N * 32) */
    vector<int> countBits(int n) {
        vector<int> ans;
        
        /* Traversing from 1 to n */
        for(int i=0; i<=n; i++) {
            int temp = i;
            int cnt = 0;
            
            /* For each i we are doing right shift until and checking if the lsb is 1 or not */
            while(temp) {
                if(temp&1) cnt++;
                
                temp = temp >> 1;
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }

    /* TC: O(N) */
    vector<int> countBits(int n) {
      vector<int> ans(n);

      ans[0] = 0;  // no. of bits for value 0 is 0

      /* consider an even number i, so the next number i.e. n+1 will be odd and it will have msb set. 
      So, the only difference between n and n+1 is the msb is set in case of n+1 */
      for(int i=1; i<=n; i++) {
        // if even then the no. of bits will be same as n/2 => through observation
        // if odd then the no. of bits will be incremented by 1
        ans[i] = ans[i/2] + (i%2);
      }
    }
};