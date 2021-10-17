#include <iostream>
using namespace std;

int getPower(int base, int index) {
	if(index == 0) return 1;
	if(index == 1) return base;

	int tempAns = getPower(base, index/2);
	if(index%2) return tempAns * base * tempAns;

	return tempAns * tempAns;
}

int main() {
	int b, i;
	cin >> b >> i;

	cout << getPower(b, i) << endl;
}