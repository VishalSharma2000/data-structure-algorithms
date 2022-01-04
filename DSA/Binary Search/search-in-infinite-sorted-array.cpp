/* 
  Given an infinite sorted array and a target element, we have to find the target element in this infinite sorted array.

  So, the approach to solve the questions is first we need to find the range of this inf sorted array in which this target element will lie.
  So, our first problem is find the range in the array in which the target element could appear.
  to do that let
  start = 0 , end = 1

  then we will iterate end = end * 2 until arr[end] > target
  so each time we check if the arr[end] >= target if it is not
  then double end i.e. end = end * 2 and also update start = prev_end
  after finding the range then we can normally binary search the element

  int start = 0, end = 1;
  while(arr[mid] < target) {
    start = end;
    end = end * 2;
  }

  binarySearch(arr, start, end);
*/

/* 
  Another extension to the problem is - find the position of first set bit in infinite binary sorted array. Means all 0s will come first and then
  all 1s will come. So, here too first find the range in which we will encounter 1 for first time and then binarySearch to find the first
  occurance of 1 in the obtained range.

*/