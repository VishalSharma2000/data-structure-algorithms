/* 
Approach: First of all we don't have any decision or choices to make. Hence we will go for IBH method (Induction-BaceCondition-Hypothesis)

sortStack(stack) => will sort the stack in ascending order <= This is my hypothesis.

Okay, now we need to figure out the base condition => which is the smallest valid input or smallest invalid input
so smallest valid input => stack has only one element or stack is empty
so whenever we see that stack is empty we can return without doing anything (we can also do the same thing when stack has only one element)

induction => 
sortStack(stack) will sort the stack so we will call the function recursively for smaller inputs, so we will pop the first element and 
call the function again to sort other elements of the stack. After receiving the sorted stack we need to insert the poped element into the stack. To do this we make another recursive function => insertSorted so for that 
hypothesis is => the function will insert the value temp inside the stack
and base condition => when stack is empty of the top element is less than the temp then directly push the element and return

otherwise pop the top element and call recursively for insertValue and then push the poped value
*/

#include <bits/stdc++.h>
using namespace std;

void insertSorted(stack<int> &in, int temp) {
  // base condition
  if(in.empty() || (in.top() < temp)) {
    in.push(temp);
    return;
  }

  // induction
  int val = in.top();
  in.pop();
  
  // hypothesis
  insertSorted(in, temp);

  // induction
  in.push(val);
}

void sortStack(stack<int> &in) {
  // base condition
  if(in.empty()) return;

  // induction
  int temp = in.top();
  in.pop();

  // hypothesis
  sortStack(in);

  // induction
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