#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> allSubsets;

void printSubsetOfArray(vector<int> &arr, vector<int> subset, int startPoint) {
  int n = arr.size();

  if(startPoint == n) {
    // we have taken decision for all the elements
    allSubsets.push_back(subset);
    return;
  }

  // don't take the current element
  printSubsetOfArray(arr, subset, startPoint+1);

  // take the current element
  subset.push_back(arr[startPoint]);
  printSubsetOfArray(arr, subset, startPoint+1);
}

void printSubset(string in, string ou) {
  if(in.length() == 0) {
    cout << ou << endl;
    return;
  }

  /* Here we have two decisions to make on each element of the string. Either we can take the element or we skip the element.
  We always do decision on first element of the string. */
  string ou1 = ou;             // don't consider first element
  string ou2 = ou + in[0];     // consider first element

  // now since decision has been taken on the first element now the input will be smaller
  string newIn = in.substr(1);

  printSubset(newIn, ou1);
  printSubset(newIn, ou2);
}

void printSubsetForString() {
  string s; cin >> s;

  // printSubset(input, output)
  printSubset(s, "");
}

void printSubsetForArray() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for(int &val : arr) cin >> val;

  // printSubsetOfArray(input, output, startPoint)
  printSubsetOfArray(arr, {}, 0);

  for(vector<int> s : allSubsets) {
    for(int val : s) {
      cout << val << " ";
    }
    cout << endl;
  }
}

int main() {
  printSubsetForArray();

  return 0;
}