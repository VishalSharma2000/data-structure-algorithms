/* Given a set of non-negative nos, we need to find if there exist any subset in this array whose sum is divisible by m */
/* So, to find if there is any subset whose sum is divisble by m we need all the different possible sum values for this array. It will definitely lie between [1 to array_sum] but their will be some values in between which will not exist. Hence to remove those values we will use subset set problem. With the help of subset sum problem we can get all possible sum values in the array */

/* TC: O(n * array_sum), SC: O(n * array_sum) */
class Solution{
	public:

		int DivisibleByM(vector<int>nums, int m){
		    int n = nums.size();
		    int sum = accumulate(nums.begin(), nums.end(), 0); // array_sum
		    
		    int dp[n+1][sum+1];
		    memset(dp, false, sizeof dp);
		    
        // initialization
		    for(int i=0; i<n+1; i++) dp[i][0] = true;
		    for(int i=1; i<sum+1; i++) dp[0][i] = false;
		    
        // classic subset sum problem
		    for(int i=1; i<n+1; i++) {
		        for(int j=1; j<sum+1; j++) {
		            if(nums[i-1] <= j) 
		                dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
		            else
		                dp[i][j] = dp[i-1][j];
		        }
		    }
		    
        // for all valid sum find if their exists any one which is divisible by m
		    for(int i=1; i<sum+1; i++) {
		        if(dp[n][i] && i%m == 0) return true;
		    }
		    
		    return false;
		}
}

/* TC: O(m * n), SC: (m) */
int DivisibleByM(vector<int>arr, int m){
		    int n = arr.size();
		    
        // with the help of pigen hole principle we can say that there will be a subset with sum equal m
		    if(n > m) return true;
		    
        // we are storing the module values
		    int dp[m];
		    memset(dp, false, sizeof dp);
		    
		    for(int i=0; i<n; i++) {
		        if(dp[0]) return true;
		        
            // we cannont directly change the dp array because it may change some future values, which will give a wrong answer
            // because in each iteration dp array stores all the possible sum%m possilbe for i-1 elements.
		        int temp[m];
		        memset(temp, false, sizeof temp);
		        
		        for(int j=0; j<m; j++) {
		            if(dp[j]) {
		                temp[(j + arr[i])%m] = true;
		            }
		        }
		        temp[arr[i]%m] = true;
		        
		        for(int j=0; j<m; j++)
		            if(temp[j])
		                dp[j] = temp[j];
		    }
		    
		    return dp[0];
		}