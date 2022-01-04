/* Find nCr in efficeint way - to avoid overflow */
/* Here we make use of the property
nCr = (n * (n-1) * ... * (n-r+1)) / (r * (r-1) * ... * 1) */
ll nCr(ll n, ll r) {
    if(r == 0 || r > n) return 0;
    if(r == n) return 1;
    if(n-r < r) r = n-r;
    
    ll ans = 1;
    for(int i=1; i<=r; i++) {
        ans *= (n-(i-1));
        ans /= i;
    }
    
    return ans;
}