/*
Given number n, find this number is lucky or not.

Classification of lucky number: The left values after following iterations
say counter = 2

1 2 3 4 5 6 7 ..... n
*/

bool helper(int n, int &counter) {
  if(counter > n) return true;
  if(n%counter == 0) return false;

  int np = n - (n/counter);
  counter++;

  return helper(np, counter);
}

bool isLucky(int n) {
  int counter = 2;

  return helper(n, counter);
}

int main() {
  int n; 
  cin >> n;

  cout << isLucky(n) << endl;
  return 0;
}