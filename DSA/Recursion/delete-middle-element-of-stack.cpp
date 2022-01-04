/* Here we are basically creating two recursive functions with different hypo
1 says that given stack and size, it will delete middle element of stack
other says that given stack and position from top delete the element at given position */
#include <iostream>
#include <stack>
using namespace std;

/* Hypo => given a stack and a position of element from top, we need to delete the element at that position */
void deleteMiddleElementUtil(stack<int> &s, int n) {
  if(s.empty()) return;
  // when we reached at required position
  if(n == 1) {
    s.pop();
    return;
  }

  int val = s.top();
  s.pop();

  deleteMiddleElementUtil(s, n-1);

  s.push(val);
}

void printStack(stack<int> &s) {
  if(s.empty()) return;

  cout << s.top() << " ";
  s.pop();

  printStack(s);
}

/* Hypo => given a stack and it's size, delete the middle element of the stack */
void deleteMiddleElement(stack<int> s, int n) {
  deleteMiddleElementUtil(s, (n+1)/2);
}

int main() {
  int n;
  cin >> n;

  stack<int> s;
  for(int i=0; i<n; i++) {
    int val; cin >> val;

    s.push(val);
  }

  deleteMiddleElement(s, (n+1)/2);
  printStack(s);
}