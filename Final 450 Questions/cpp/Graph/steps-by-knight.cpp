/* 
Given the knight position and the target position, we have to find the minimum number of steps required to reach the target position
https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1
*/

/* Approach: It's basically a normal BFS approach, and as we know that doing bfs gives us the minimum distance from source to destination.
So, doing a normal bfs we can get the shortest distance to reach from source to destination */

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
	int minStepToReachTarget(vector<int>& k, vector<int>& t, int N) {
	    vector<vector<bool>> visited(N+1, vector<bool> (N+1, false));
	    queue<pair<int, int>> q;
	    
	    visited[k[0]][k[1]] = true;
	    q.push({ k[0], k[1] });
	    int minStep = 0;
	    
	    while(!q.empty()) {
	        int size = q.size();
	        while(size--) {
	            int r = q.front().first, c = q.front().second;
	            q.pop();
	            
              /* If we reached the destination, then return the minStep */
	            if(r == t[0] && c == t[1]) return minStep;
	            
              /* All 8 directions for knight */
              int dir[][2] = {{2, -1}, {2, 1}, {-2, -1}, {-2, 1}, {-1,2}, {1, 2}, {-1,-2}, {1, -2}};
	            for(int i=0; i<8; i++) {
	                int nr1 = r + dir[i][0];
	                int nc1 = c + dir[i][1];
	                
	                if(nr1 < 0 || nr1 > N || nc1 < 0 || nc1 > N || visited[nr1][nc1]) continue;
	                
	                visited[nr1][nc1] = true;
	                q.push({ nr1, nc1 });
	            }
	        }
	        
	        minStep++;
	    }
	    
	    return minStep;
	}
};