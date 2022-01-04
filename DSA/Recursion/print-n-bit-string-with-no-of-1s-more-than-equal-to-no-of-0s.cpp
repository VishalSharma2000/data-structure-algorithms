/* Problem Statement: Given the value n, print all n-size bits where all prefix of the string should satify the condition i.e. number of 1s >= no. of zeros 
GFG Question: https://practice.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1
*/

/* In total we have n position to fill. At each position we have a  choice to either fill 0 or 1. 
While making the recursive tree it's clear that we will always have the choice to choose 1 at any position but we will only have the choice to choose 0 at a position i when frequency of 1 till i-1 is more than frequency of 0
i.e. cnt(1) > cnt(0) { we can choose 0 also } 

in total if the zerocnt and onecnt == n then we have filled all positions so that is our base condition*/
#include <iostream>
#include <string>
using namespace std;

void printAllBitsHelper(int n, int oneCnt, int zeroCnt, string ou) {
  if(oneCnt + zeroCnt == n) {
    cout << ou << endl;
    return;
  }
  
  // There will always have an option of choosing 1 in the current place
  string ou1 = ou + "1";
  printAllBitsHelper(n, oneCnt + 1, zeroCnt, ou1);

  // There will be choice of choosing 0 when difference between oneCnt and zeroCnt > 0
  if((oneCnt - zeroCnt) > 0) {
    string ou1 = ou + "0";
    printAllBitsHelper(n, oneCnt, zeroCnt + 1, ou1);
  }
}

void printAllBits(int n) {
  int oneCnt = 0;
  int zeroCnt = 0;

  string out = "";

  printAllBitsHelper(n, oneCnt, zeroCnt, out);
}

int main() {
  int n;
  cin >> n;

  printAllBits(n);
}