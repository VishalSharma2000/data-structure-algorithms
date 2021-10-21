/* TC: O(m*Log(n)), SC: O(1) */
class Solution {
public:
  int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int maxOnes = 0, maxOnesInd = -1;
	    for(int i=0; i<n; i++) {
	        int ind = upper_bound(arr[i].begin(), arr[i].end(), 0) - arr[i].begin();
	        
	        if(m-ind > maxOnes) {
	            maxOnes = m-ind;
	            maxOnesInd = i;
	        }
	    }
	    
	    return maxOnesInd;
	}
};

/* Optimization of above approach, worst case: O(M*Logn) */
// class Solution {
// public:
//   int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
// 	    int firstOne;

//       int firstOne = upper_bound(arr[0].begin(), arr[0].end(), 0) - arr[0].begin();
//       int maxOneInd = firstOne == m ? -1 : 0;

// 	    for(int i=1; i<n; i++) {
// 	        if(firstOne-1 >=0 && arr[i][firstOne-1] == 1) {
//             firstOne = upper_bound(arr[0].begin(), arr[0].begin()+firstOne, 0);
//             maxOneInd = i;
//           } 
// 	    }
	    
// 	    return maxOnesInd;
// 	}
// };


/* TC:O(m + n), SC: O(1) */
class Solution {
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int firstOne = upper_bound(arr[0].begin(), arr[0].end(), 0) - arr[0].begin();
	    int rowIndex = firstOne == m ? -1 : 0;
	    
	    for(int i=1; i<n; i++) {
	        while(firstOne-1 >=0 && arr[i][firstOne-1] == 1) {
	            firstOne--;
	            rowIndex = i;
	        }
	    }
	    
	    return rowIndex;
	}

};