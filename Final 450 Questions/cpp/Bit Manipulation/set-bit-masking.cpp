/* Design a set data structure which can store number in range 0 to 63 and perform add, remove and update operation in O(1) time and O(1) space */
/* We can make use of bit masking to do it */

#include <bits/stdc++.h>
using namespace std;

class SetDS {
  long long int exist = 0;

  public:
  void add(int no) {
    // cout << (1<<no) << endl;
    exist = exist | (1 << no);
  }

  void remove(int no) {
    exist = exist & ~(1 << no);
  }

  void print() {
    for(int i=0; i<64; i++) {
      if(exist & (1<<i)) cout << i << " ";
    }
    cout << endl;
  }
};

int main() {
  SetDS s = SetDS();

  s.add(10);
  s.add(15);
  s.add(41);
  s.add(1);

  s.print();
}