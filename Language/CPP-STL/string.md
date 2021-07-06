int main() {
string s1 = "stringcomparison";
string s2 = "playingwithstringsbithard";

/_ Compare Two strings _/
/\* 1) Operators (<, >, =) - returns boolean either true or false
eg: s1 == s2 => if both strings are same then return true else false
s1 < s2 => if string s1 is lexiographically smaller than string s2 then return true else false.

    2) compare function
      -> s1.compare(s2)
      if < 0 => s1 is smaller than s2
         > 0 => s1 is greater thans s2
         = 0 => s1 and s2 are same

      Whatever value you will get will be the difference of the summation of ascii value

\*/
}

### Convert String to Other Datatypes

1.  ### How are strings literal stored in string class.

    - Whenever we declare a string using char\* it is stored in read only memory and hence its immutable. But when we store the string or
      copy the string value from the pointer to std::string then the copy of the string is present in the string object. You can also think
      that the string literal is converted in array of characters. Hence, std::string in cpp are muttable while it's immutable if you declare
      it other ways.

2.  ### Using stoi and atoi
    - stoi convert strings to interger
    - atoi convert array of characters to integer

## String Operations

```
/* Find Operations */
/* Find one character or string into another string */

void letsLearnString(string s1, string s2, char ch1) {
  // Now we want to find string s2 in s1 and character ch1 in s1

  /* We can do it using s1.find(params)
    params => s2 (if we want to find s2 in s1)
    params => ch1 (if we want to find character in s1)
    params => s2, start_pos, len (if we want to find a substring of s2 starting at position start_pos of length len)

    If found then the first index of the string or character will be returned otherwise npos (a static largest value) will be returned
   */

  if(s1.find(s2) == string::npos) {
    cout << "s2 not found in s1" << endl;
  }
}
```
