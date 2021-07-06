/* Given two strings we have to find if string s1 is rotation of string s2 */

/* Normal Intuitive Approach */
/* We will rotate the string s1 by one position and after each rotation we will check if the string s1 is present in string s2 */

/* Now there are two ways of finding all the rotations of the string s1. 
One way is to manully rotate and then check if the new achieved string is equalt to s2
else
we can just concatinate string s1 two times i.e. new_string = s1 + s1
Now if we traverse from i = 0 to n-1 (at each index we will get the starting point of next rotation) 

eg: s1 = "ABC"
  new_string = s1 + s1 = "ABC" + "ABC" = "ABCABC"
  so if i = 0, then r1 = "ABC"
  so if i = 1 then r2 = "BCA"
  so if i = 2 then r3 = "CAB"
  so we got all the rotations
*/
#include <bits/stdc++.h>
using namespace std;

bool isRotation(string s1, string s2) {
  int len1 = s1.length(), len2 = s2.length();

  if(len1 != len2) return false;

  string temp = s1 + s1;
  return temp.find(s2) != string::npos;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;

  cout << isRotation(s1, s2) << endl;
}