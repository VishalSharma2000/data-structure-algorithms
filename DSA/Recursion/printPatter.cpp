#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define nl '\n'

void printNumber(int n) {
    cout << n << " ";
    
    // base condition
    if(n <= 0)  return;
    
    printNumber(n-5);
    cout << n << " ";
}

int main()
{
    ll t;
    cin >> t;
    
    while(t--) {
        ll n;
        cin >> n;
        
        printNumber(n);
        cout << endl;
    }
	
	return 0;
}