#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int> &in, int temp) {
  if(in.empty() || (in.top() < temp)) {
    in.push(temp);
    return;
  }

  int val = in.top();
  in.pop();
  insertSorted(in, temp);
  in.push(val);
}

void sortStack(stack<int> &in) {
  if(in.empty()) return;

  int temp = in.top();
  in.pop();
  sortStack(in);
  insertSorted(in, temp);
}

void printStack(stack<int> in) {
  if(in.empty()) return;

  cout << in.top() << endl;
  in.pop();
  printStack(in);
}

int main() {
  int n; 

  stack<int> in;
  while(cin >> n) {
    if(n == -1) break;
    in.push(n);
  }

  printStack(in);
  sortStack(in);
  printStack(in);

  return 0;
}