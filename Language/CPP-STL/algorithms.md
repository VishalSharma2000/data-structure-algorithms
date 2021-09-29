## Algorithms

```
vector<int> vec{1,4,1,6,7,2,4,9,0};
```

| Code Snippet                                                 | Use                                                                                                        |
| ------------------------------------------------------------ | ---------------------------------------------------------------------------------------------------------- |
| sort(startIterator, endIterator)                             | sort the array or vector elements from startIterator till endIterator-1                                    |
| \*max_element(startIterator, endIterator)                    | Find the maximum element in array from startIterator till endIterator-1                                    |
| \*max_element(startIterator, endIterator) - startIterator    | Find the index of max element in the array from startIterator till endIterator-1                           |
| \*min_element(startIterator, endIterator)                    | Find the min element                                                                                       |
| \*min_element(startIterator, endIterator) - startIterator    | Find the index of min element                                                                              |
| count(startIterator, endIterator, val)                       | Find the occurance of val in array from startIterator to endIterator-1                                     |
| sum(startIterator, endIterator, val)                         | Find the sum of array elements from startIterator to endIterator-1 with val as the starting value          |
| next_permutation(startIterator, endIterator) <br /> TC: O(N) | Find the next lexiographical permutation <br /> Returns true if the next permutation exist otherwise false |
| prev_permutation(startIterator, endIterator) <br /> TC: O(N) | Find the prev lexiographical permutation <br /> Returns true if the prev permutation exist otherwise false |

## Left and Right rotation
    rotate(startIterator, middleIterator, endIterator);
    
- startIterator and endIterator indicate the range of the array where rotation needs to be performed.
- middleIterator is the iterator which should be between startIterator and endIterator and should be pointing to the element which you want to become the first element after rotation in the given range 

 ### Left rotation
- All the iterators should be forward Iterator

 ### Right Rotation
- All the iterators should be backward Iterator

## Examples
```
  vector<int> arr{1, 2, 3, 4, 5, 6, 7};
  auto it = arr.begin();

  // Left shift from index [1, 5) by 2
  rotate(arr.begin() + 1, arr.begin() + 3, arr.end() - 2);
  /*
    arr.begin() => points to element at index 1
    arr.end() => points to elemnt at index 5
    arr.begin() + 3 => points to 4 
  */

  for(auto it=arr.begin(); it!=arr.end(); it++) cout << *it << " ";
  // 1 4 5 2 3 6 7

  // Right shift complete array by 5 (so that 2 is at last position)
  rotate(arr.rbegin(), arr.rend()-2, arr.rend()); 

  for(auto it=arr.begin(); it!=arr.end(); it++) cout << *it << " ";
  //3 4 5 6 7 1 2
```