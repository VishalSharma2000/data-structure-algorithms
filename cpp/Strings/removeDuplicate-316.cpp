class Solution
{
public:
  string removeDuplicateLetters(string s)
  {
    int n = s.length();
    if (n == 0)
      return "";

    bool visited[26] = {false};
    // for keeping the track of which character is already visited and which are not

    int lastOcc[26] = {-1};
    // for keeping the last occurance index of the character in the string
    for (int i = 0; i < n; i++)
      lastOcc[s[i] - 'a'] = i;

    stack<char> st;
    for (int i = 0; i < n; i++)
    {
      if ((st.empty() or st.top() < s[i]) and !visited[s[i] - 'a'])
      {
        // if the stack is empty, then we insert the first character if we have not yet visted it.
        // if the stack is not empty, and the coming new character is greater than the top character of the stack, and not yet visited then we are correct on the lexographical side. so push the character into the stack
        st.push(s[i]);
        visited[s[i] - 'a'] = true;
      }
      else
      {
        // if we already have some characters in the stack or
        // if the coming character is already visited, then we should check for the lexographical side
        while (!st.empty() and lastOcc[st.top() - 'a'] > i and st.top() > s[i] and !visited[s[i] - 'a'])
        {
          // while the stack is not empty, and the top character of stack is again occuring later in the string
          // and also it is greater than the coming character and also the coming character is not yet visited ...so to make the resultant string lexographical we should keep the lower character first and higher later
          // so pop the character from the stack
          visited[st.top() - 'a'] = false;
          st.pop();
        }

        if (!visited[s[i] - 'a'])
        {
          // now push the coming character if not visited..
          // this if will be useful for the cases like ddcbc...try dry run without if you will understand
          st.push(s[i]);
          visited[s[i] - 'a'] = true;
        }
      }
    }

    string ans = "";
    while (!st.empty())
    {
      // cout << st.top() << endl;
      ans = st.top() + ans;
      st.pop();
    }

    return ans;
  }
};