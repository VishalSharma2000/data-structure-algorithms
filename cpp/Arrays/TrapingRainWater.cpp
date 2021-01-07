// O(n^2) approach
class Solution
{
public:
  int trap(vector<int> &height)
  {
    int n = height.size();
    if (n == 0)
      return 0;

    int prevWater = 0;
    int water = 0;
    while (1)
    {
      for (int i = 1; i < n - 1; i++)
      {
        int j = i - 1, k = i + 1;
        for (; j >= 0; j--)
          if (height[j] > height[i])
            break;

        for (; k < n; k++)
          if (height[k] > height[i])
            break;

        if (j == -1 || k == n)
          continue;
        // cout << i << " " << j << " " << k << " ";
        // int dist = k-j-1;
        int hei = min(height[k], height[j]) - height[i];
        // cout << dist << " " << hei << endl;
        water += hei;
        height[i] = height[i] + hei;
      }

      if (prevWater == water)
        break;
      prevWater = water;
    }

    return water;
  }
};

// O(N) approach with O(N) space
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        if(n <= 2) return 0;
        
        int water = 0;
        int left[n], right[n];
        left[0] = height[0];
        right[n-1] = height[1];
        
        for(int i=1; i<n; i++) left[i] = max(left[i-1], height[i]);
        for(int i=n-2; i>=0; i--) right[i] = max(right[i+1], height[i]);
        
        for(int i=1; i<n; i++) {
            water += max(0, min(right[i],left[i])-height[i]);
        }
        
        return water;
    }
};