// When travelling in the graph, optimal strategy to travel is in diagonal direction. Then after that travel the straight path.

class Solution
{
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points)
  {
    int n = points.size();

    if (n == 1)
      return 0;

    int sec = 0;
    for (int i = 0; i < n - 1; i++)
    {
      int a1 = points[i][0], b1 = points[i][1];
      int a2 = points[i + 1][0], b2 = points[i + 1][1];

      int d = min(abs(a1 - a2), abs(b1 - b2));
      int s = max(abs(a1 - a2), abs(b1 - b2)) - d;

      sec += (d + s);
    }

    return sec;
  }
};