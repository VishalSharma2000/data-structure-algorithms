/*
  Scramble String.
  Given two string we have to return true if both the strings are scramble string of each other otherwise false.

  Two Strings are called scramble string in following condition (This condition depends on the question, it does not remain same everywhere)
  1) Convert the string into binary tree such that no child is empty ("") string. Each child should atleast have one character
  eg:  great
      /     \
     gr     eat
    / \    /  \
   g   r  e   at
             /  \
            a    t
  2) We can now swap the child of non-leaf nodes (here they are => great, gr, eat). Swapping means interchanging the child nodes. 
  So, gr can be converted into rg by swapping g with r, similarly eat can be changed to ate by swapping e and at...
  so after swapping whatever string is obtained is the scramble string of the original string. 

  Here, the swapping can be one or more...so all possible swappings will be scramble string of each other. 
  great <=> rgeat
  great <=> rgate
  great <=> great 
  ,etc
*/

#include <bits/stdc++.h>
using namespace std;

bool isScramble(string s1, string s2) {
  int len1 = s1.length();
  int len2 = s2.length();

  if(len1 != len2) return false;
  /* Swapping cannot result into an increase or decrease of the length of the given strings */
  if(len1 == 0 || len2 == 0) return false;
  /* As per the defination, either of the strings should not be empty */
  if(s1.compare(s2) == 0) return true;
  /* If both the strings are same, then also they are scrambled */
  if(len1 == 1) return false;
  /* We have already checked that the string is of equal length, and none of them is empty, and even they are not equal
     so if they are of length one then no definately they are not equal  */

  for(int i=1; i<len1; i++) {
    /* If swapping wouldn't have happened */
    /* Then the first i characters of string s1 should be same to first i characters of string s2, same thing should hold for remaing n-i characters  */
    bool nonSwapCond = isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i));

    /* If swapping would have happened */
    /* Then the first i characters should be same as last i characters,  */
    bool swapCond = isScramble(s1.substr(0, i), s2.substr(len1-i)) && isScramble(s1.substr(i), s2.substr(0, len1-i));

    if(nonSwapCond || swapCond) return true;
  }

  return false;
}

int main () {
  string s1, s2;
  cin >> s1 >> s2;

  cout << isScramble(s1, s2) << endl;
}