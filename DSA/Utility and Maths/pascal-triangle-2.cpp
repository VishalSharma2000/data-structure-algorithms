/* Given the row Index we have to print all the elements of row equal to rowIndex */

/* TC: O(k^2), SC: O(K) */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // no. of elements in a particular row = row number + 1
        /* If row = 1, no. of elements = 2,
        row = 4, no. of elements = 5
        row = rowIndex, no. of elements = rowIndex + 1 */
        vector<int> ans(rowIndex+1, 0);
        
        ans[0] = 1; // initialize

        // for all rows
        for(int i=1; i<=rowIndex; i++) {
            for(int j=i; j>=1; j--) {
                /* In each row a newer element equal to 1 will be added at last, then */
                /* ans[j] = ans[j] + ans[j-1] */ 
                ans[j] += ans[j-1];
            }
        }
        
        return ans;
    }
};

/* TC: O(K), SP: O(K) */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        
        // initialize
        ans[0] = ans[rowIndex] = 1;
        long comb = 1;
        int j = 1;
        
        /* for rowIndex r elements of row are 
        rC0, rC1, rC2, rC3, ... , rCr
        rC0 = rCr = 1

        Let r = 5
        5C1 = 5 / 1
        5C2 = 5 * 4 / 2 * 1
        5C3 = 5 * 4 / 2 * 1
        5C4 = 5 / 1

        Let r = 9
        9C0 = 1
        9C1 = 9                                 (Mul by 9)
        9C2 = 9 * 8 / 2 * 1                     (Mul Numerator by 8 , denominator by 2)
        9C3 = 9 * 8 * 7 / 3 * 2 * 1             (Mul Numerator by 7, denominator by 3)
        9C4 = 9 * 8 * 7 * 6 / 4 * 3 * 2 * 1     (Mul Numerator by 6, denominatro by 4)
        9C5 = 9 * 8 * 7 * 6 / 4 * 3 * 2 * 1     (same as 9c4)
        9C6 = 9 * 8 * 7 / 3 * 2 * 1             (same as 9c3)
        9C7 = 9 * 8 / 2 * 1                     (same as 9c2)
        9C8 = 9 / 1                             (same as 9c1)
        9C9 = 1
        */
        for(int i=rowIndex; i>rowIndex/2; i--) {
            comb *= i;
            comb /= j;
            
            j++;
            
            ans[i-1] = (int) comb;
            ans[j-1] = (int) comb;
        }
        
        return ans;
    }
};