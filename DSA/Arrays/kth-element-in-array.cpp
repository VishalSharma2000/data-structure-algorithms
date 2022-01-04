/* Given an array which may contain repeating elements find the kth largest / smallest number */
/* Approach: We would need to use set stl data structure to find all the unique elmenets in the array and since set stores the elements
in sorted order we can just return the value at (k)th position if smallest value is asked or (n-k)th position if largest value is asked(1 based indexing) */