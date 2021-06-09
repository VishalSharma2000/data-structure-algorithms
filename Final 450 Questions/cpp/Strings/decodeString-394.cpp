class Solution
{
public:
  string decodeString(string s)
  {
    int len = s.length();
    if (len == 0)
      return "";

    stack<string> s1;
    stack<int> s2;
    for (int i = 0; i < len; i++)
    {
      string temp = s.substr(i, 1);
      if (s[i] == '[')
      {
        s1.push(temp);
      }
      else if (s[i] == ']')
      {
        string st = "";

        while (!s1.empty() && s1.top() != "[")
        {
          st = s1.top() + st;
          s1.pop();
        }
        s1.pop();

        int t = 1;
        if (!s2.empty())
        {
          t = s2.top();
          s2.pop();
        }

        string finalStr = "";
        for (int i = 0; i < t; i++)
          finalStr += st;
        s1.push(finalStr);
      }
      else if (s[i] >= 'a' && s[i] <= 'z')
      {
        s1.push(temp);
      }
      else
      {
        string temp = "";
        while (s[i] >= '0' && s[i] <= '9')
        {
          temp = temp + s[i];
          i++;
        }
        i--;
        int t = stoi(temp);
        // cout << t << endl;
        s2.push(t);
      }
    }

    string ans = "";
    while (!s1.empty())
    {
      ans = s1.top() + ans;
      s1.pop();
    }

    return ans;
  }
};