**[Leetcode Question](https://leetcode.com/problems/robot-bounded-in-circle/)** 

We have to find if we can make a circle on the infinite plane such that the robot only remains in the circle. So, we have to find where the robot is finishing after each simulation of the string. 
Now, to figure out the final position of the robot after one simulation we have to find values which should be added to the current position of the robot depending on the direction the robot is facing.

So, on observation

| Direction | Add | L | R |
| ----------|-----|---|---|
| North | (0, 1) | West | East |
| West  | (-1, 0) | South | North |
| East | (1, 0) | North | South |
| South | (0, -1) | East | West |

So, we can make use of the above direction matrix to add the correspoding x and y values in the current position and also to identify the final direction the robot is facing.

So, the key point is.... **Since we are simulating the same string infinite number of times, robot will be contrainted in the same area only when it keeps on rotating the same circular path i.e. after some k simulations of the string the robot should definitely come back to it's original position i.e. (0, 0).**

<span style="color: red">**_So the conclusion comes out that - after one simulation the direction of the robot should be changed or if the direction does not change, then the robot should be at (0, 0), i.e. it did not move from it's starting point or again came back to it's starting point after one simulation._**<span>

```
class Solution {
public:
    bool isRobotBounded(string ins) {
        vector<pair<int, int>> direction{{1, 2}, {3, 0}, {0, 3}, {2, 1}};
        vector<pair<int, int>> addPoints{{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
        
        if(count(ins.begin(), ins.end(), 'G') == 0) {
            return true;
        }
        
        int x = 0, y = 0;
        int dir = 0;
        for(int i=0; i<ins.size(); i++) {
            if(ins[i] == 'G') {
                x += addPoints[dir].first;
                y += addPoints[dir].second;
            } else {
                dir = ins[i] == 'L' ? direction[dir].first : direction[dir].second;
            }
        }
        
        if((dir != 0) || (x == 0 && y == 0)) {
            return true;
        }
        
        return false;
    }
};
```

