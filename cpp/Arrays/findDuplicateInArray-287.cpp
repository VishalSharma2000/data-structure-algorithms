/* 
You are given an array of length n+1 and
1 <= arr[i] <= n
So, it clear that one element is present two times in the array
We have to find that duplicate element
*/

/*
Approach 1: 
Find the frequency for each element of the array, while doing so check if the freq[arr[i]] > 1 then return that number
Its almost like using set to find the elements which are already present.
*/

// snippet
int freq[n] = {0};
for (int i=0; i<n; i++) {
    freq[arr[i]]++;
    if(freq[arr[i] > 1) return arr[i];
}

/*
 Time complexity : O(n)
 Space Complexity : O(n)
*/

/*
Approach 2: 
Sort the array and check the adjacent elements of the array, Duplicate elements will be present together

Time Complexity: O(nLog(n)) --- depends on which sorting algorithm you use
Space Complexity: O(n) or O(1) --- depends on which sorting algorithm you use
*/

/*
Effiecient Approach
Floyd's Tortoise and Hare 

Its basically a two pointer approach, tortoise resemble slow pointer and hare the faster one.
This method is also used to find the cycle in linked list, get the starting point of cycle in linked in.

So, here we are using the value of array to point to the next element....
tortoise = arr[tortoise]
hare = arr[arr[hare]]

when the two meets, we are in the cycle but not necessarily at the starting point of the cycle. To Get the starting point we have to restart tortoise from start point and reduce the speed of hare to move one element at a time...
*/

int findDuplicate(vector<int> &arr) {
    int n = arr.size();

    int tortoise = arr[0];
    int hare = arr[0];

    do {
        tortoise = arr[tortoise];
        hare = arr[arr[hare]];
    } while (tortoise != hare);

    // restart the tortoise
    while (tortoise != hare) {
        tortoise = arr[tortoise];
        hare = arr[hare];
    }

    return hare;
}



