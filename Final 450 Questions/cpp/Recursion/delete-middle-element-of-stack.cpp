#include <iostream>
#include <stack>
using namespace std;

void deleteMiddleElement(stack<int> &s, int n) {
  if(s.empty()) return;
  if(n == 1) {
    s.pop();
    return;
  }

  int val = s.top();
  s.pop();

  deleteMiddleElement(s, n-1);

  s.push(val);
}

void printStack(stack<int> &s) {
  if(s.empty()) return;

  cout << s.top() << " ";
  s.pop();

  printStack(s);
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