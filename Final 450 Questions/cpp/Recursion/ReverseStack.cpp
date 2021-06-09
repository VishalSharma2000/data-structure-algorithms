/*
Reverse stack using recursion and with basic operation of stack (push, pop, empty)

Time complexity: O(n^2)
For each value of n, we will insert that value at the bottom of the stack...
for insertion at bottom worst case time complexity is O(n) and we have n elements
so therefore, O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int val) {
  if(s.empty()) s.push(val);
  else {
    int temp = s.top();
    s.pop();
    // keeping the top value in temporary variable

    insertAtBottom(s, val);

    s.push(temp);
  }
}

void reverseStack(stack<int> &s) {
  if(s.empty()) return;

  // storing all the values of stack in the variable 
  // and this variable is stored in the inner stack used by the compiler
  int val = s.top();
  s.pop();

  reverseStack(s);  
  insertAtBottom(s, val);
}

void printStack(stack<int> s) {
  if(s.empty()) return;

  cout << s.top() << " ";
  s.pop();
  printStack(s);
}

int main() {
  stack<int> s({1, 2, 3, 4, 5}); // initial value
  
  reverseStack(s);
  printStack(s);
}