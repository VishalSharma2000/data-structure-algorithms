#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define nl '\n'

int main()
{
    ll t;
    cin >> t;
    
    while(t--) {
        int m, n; 
        cin >> m >> n;
        
        map<int, int> freq1;
        map<int, int> freq2;
        int no;
        for(int i=0; i<m && cin >> no; i++) freq1[no]++;
        for(int i=0; i<n && cin >> no; i++) freq2[no]++;
        
        bool status = true;
        for(auto it=freq2.begin(); it!=freq2.end(); it++) {
            if(freq1[it->first] < it->second) {
                status = false;
                break;
            }
        }
        
        if(!status) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
	
	return 0;
}