/*
Form a set of the unique nos from the given array. Since the set is internally implemented as tree...
so insertion in set means log(n) 

After making the set of unique elements, traverse through the set checking that (i-1)th + 1 = ith or not....
if yes len++;
else len=1;

Time complexity: O(nLog(N))
*/
class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    int n = nums.size();

    if (n < 2)
      return n;
    set<int> ans;
    for (int i = 0; i < n; i++)
    {
      ans.insert(nums[i]);
    }

    int len = 1, maxLen = 1;
    auto prev = ans.begin();

    for (auto it = ans.begin(); it != ans.end(); it++)
    {
      if (*it == *prev + 1)
        len++;
      else
        len = 1;

      maxLen = max(maxLen, len);
      prev = it;
    }

    return maxLen;
  }
};

// O(n)

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    int n = nums.size();

    if (n < 2)
      return n;

    unordered_set<int> ans;
    for (int i = 0; i < nums.size(); i++)
      ans.insert(nums[i]);

    int len = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (ans.find(nums[i] - 1) == ans.end())
      {
        int j = nums[i];
        while (ans.find(j) != ans.end())
          j++;

        len = max(len, j - nums[i]);
      }
    }

    return len;
  }
};