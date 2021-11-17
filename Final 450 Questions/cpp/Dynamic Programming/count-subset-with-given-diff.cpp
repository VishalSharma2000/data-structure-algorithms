/* Given an array of elements and a number x, we have to find the count of pair of subsets with sum difference equal to x
  so let s1 and s2 be the sum of any two subsets

  so we have to find s1 - s2 = x
  but s1 + s2 = array_sum

  so 2*s1 = x + array_sum
  so s1 = (x + array_sum) / 2

  so the problem reduces to finding the count of subsets in the array with sum equal to s1
 */