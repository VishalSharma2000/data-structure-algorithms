/* O(min(r, n-r)^2)*(logn) - Used when n >> r or n-r >> r */
int gcd(int a, int b) {
    if(b == 0) return a;
    
    return gcd(b, a%b);
}

long long bc(int n, int r) {
    if(n-r < r) 
        r = n-r;
    
    vector<int> arr(r);
    iota(arr.begin(), arr.end(), n-r+1); // store the values from (n-r+1 to n) - basically it represents the 
    
    for(int i=1; i<=r; i++) {
        int j = 0, k = i;
        while(j < r) {
            int g = gcd(arr[j], k);
            if(g > 1) {
                k /= g;
                arr[j] /= g;
            }
            
            if(k == 1) break;
            j++;
        }
    }
    
    long long res = 1;
    for(int i=0; i<r; i++) 
        res *= arr[i];
    
    return res;
}

int main() {
    int n = 5;
    int r = 2;
    
    cout << bc(n, r) << endl;
}