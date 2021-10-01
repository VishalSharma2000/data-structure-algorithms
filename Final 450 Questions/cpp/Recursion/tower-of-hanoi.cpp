/* Recurrance relation: T(n) = 2 *T(n-1) + 1 */
#include <iostream>
using namespace std;

void performTowerOfHanoi(int disks, char src, char dest, char temp) {
  if(disks == 1) {
    printf("Move disks %d from %c to %c\n", disks, src, dest);
    return;
  }

  performTowerOfHanoi(disks-1, src, temp, dest);
  printf("Move disks %d from %c to %c\n", disks, src, dest);
  performTowerOfHanoi(disks-1, temp, dest, src);
}

int main() {
  int disks;
  cin >> disks;

  char src = 'A';
  char temp = 'B';
  char dest = 'C';

  performTowerOfHanoi(disks, src, dest, temp);
}