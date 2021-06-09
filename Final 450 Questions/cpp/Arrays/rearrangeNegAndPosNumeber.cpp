// Rearrange the elements of array such that the negative and positive numbers are alternate to each other...
// OR rearrange such that even positive acquire positive number and 
// odd positition acquire negative value
// If neg and pos values are not equal then place the extra values together at the end.



// Time complexity => O(n)
// Space Complexity => O(1)
// Drawback => Relative ordering of negative and positive values are not maintained bcoz we are using Quick sort logic to sort the number quickly..
// and quick sort is not relative ordering sorting algorithm.
int main() {
    int arr[] = {-1, -2, -3, -4, 
				5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // quick sort to bring all negative and positive elements together respectively
    int i = 0;
    for(int j=0; j<n; j++) 
        if(arr[j] < 0) 
            swap(arr[i++], arr[j]);
    
    int pos = i, neg = 1;
    // we want negative values in odd position i.e. at index 1, 3, 5, ....
    while(pos < n && arr[neg] < 0) {
        // till positive number exist and the negative pointer is pointing to a negative value 
        // OR
        // while until pos and neg pointers are pointing to positive and negative value respectively
        swap(arr[pos], arr[neg]);
        neg += 2;
        pos++;
    }
    
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}

// if we want to maintain the relative ordering of the numbers we can solve the problme in O(N) extra space
int main() {
    int arr[] = {-1, -2, -3, -4, 
				5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    vector<int> pos, neg;
    for(int i=0; i<n; i++) if(arr[i] > 0) pos.push_back(arr[i]); else neg.push_back(arr[i]);
    
    int temp[n];
    int p = 0, n1 = 0;
    for(int i=0; i<n; i++) {
        if(i%2 == 0) 
            if(p < pos.size()) temp[i] = pos[p++];
            else temp[i] = neg[n++];
        else 
            if(n1 < neg.size()) temp[i] = neg[n1++];
            else temp[i] = pos[p++];
    }
    
    for(int i=0; i<n; i++) cout << temp[i] << " ";
    cout << endl;
}