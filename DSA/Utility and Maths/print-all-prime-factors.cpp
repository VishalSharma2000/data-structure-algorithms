/* Print all the prime factors of the given number */
void printPrimeFactors(int n) {
    while(n%2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }
    
    for(int i=3; i<=sqrt(n); i += 2) {
        while(n%i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    
    if(n > 2) {
        cout << n << endl;
    }
}

int main() {
    int n = 10;
    
    printPrimeFactors(n);
}