```

int createAtoi(string s) {
    int i = 0, n = s.size();

    // ignore all the starting white spaces
    while(s[i] == ' ') i++;

    // since the first occurence of + / - is only considered for
    // determining if the number is +ve or -ve
    bool pos = true;
    if(s[i] == '+') pos = true, i++;
    else if(s[i] == '-') pos = false, i++;

    // iterate till we are observing numeric characters
    int sum = 0;
    while(s[i] >= '0' && s[i] <= '9') {
        int no = s[i] - '0';

        if(pos && 1LL * sum * 10 + no >= INT_MAX) return INT_MAX;
        if(!pos && 1LL * sum * 10 + no > INT_MAX) return INT_MIN;

        sum = sum * 10 + no;
        i++;
    }

    return pos ? sum : -sum;
}

```