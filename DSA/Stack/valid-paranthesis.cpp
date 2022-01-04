/* Given a string of paranthesis ( and ) we need to find weather it is balanced or not */

/* One way to solve the question is by using stack */
/* 
  Another way to solve the question is by applying prefix sum
  Convert the string into array such that open bracket '(' will be written as +1 and ')' as -1. Then find the prefix sum of the array. 
  for example: (()()(()))
  so the array will be => [1, 1, -1, 1, -1, 1, 1, -1, -1, -1] and
  prefix sum => [1, 2, 1, 2, 1, 2, 3, 2, 1, 0]

  so in the prefix sum if all the values are >= 0 then the bracket sequence is balanced otherwise not balanced. 
  The thing to note that - Thinking that 0 at the end will say that the seq is balanced is wrong. consider this case
  s = ))(( => the last value of prefix sum in this case will be 0 but this is not balanced
  s = (()))()( => here also the last value will be 0 in prefix sum but the seq is not balanced

  for both of the above cases there will be atleast one element in the array which is less than 0, hence stating that the seq is not balanced 
*/

/* Another thing to note in valid paranthesis question is - each bracket in the sequence has a fixed exactly one opposite bracket. 
eg: ( ) ( ( ) ) ( )
    0 1 2 3 4 5 6 7

    mapped with
    0 => 1
    2 => 5
    3 => 4
    6 => 7

    so it will never happen that 0 in some case will map with some other bracket position to make the sequence balance.
 */