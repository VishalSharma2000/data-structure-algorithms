/* Problem Stmt: Given an array of interger we have to find the minimum difference between two subset of the array */

/* Approach: Since we don't have any sum given in the question we will have to first figure out what will be the value or range of sum value. So, it can be seen that the range for sum will be from 0 to totalArrSum.

So, we can find all the valid sum values with the help of subset sum problem solution before totalArrSum/2, bcoz for the sum of second subset we can directly subtract it from the totalArrSum */