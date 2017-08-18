#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** = number of times c occurs in s. */
int numberc(char c, char* s) {
  if(strlen(s)==0){
    return 0;
  }
	if(c!=s[0]){
    return numberc(c,s+1);
  }
  else{
    return 1+numberc(c,s+1);
  }

}

 /** = number of chars in s that are not c. */
int numberNotc(char c, char* s) {
  if(strlen(s)==0){
     return 0;
  }
  if(c!=s[0]){
    return 1+numberNotc(c,s+1);
  }
	else{
    return numberNotc(c,s+1);
  }

}

/** = a copy of s but with all occurrences of c replaced by d.
Example: replace("abeabe", 'e', '$') = "ab$ab$".
*/
char* replace(char* s, char c, char d) {
  char* str1;
  char* str2;
  if (strlen(s) == 0){
    return "";
  }
  str1 = (char *)malloc(strlen(s)+1);
  if (s[0] == c){
     str1[0] = d;
  }
  else {
    str1[0] = s[0];
  }
  str1[1] = '\0';
  str2 = replace(s+1, c, d);
  strcat(str1, str2);
  free(str2);
  return str1;

}


 /** = a copy of s with adjacent duplicates removed.
 Example: for s = "abbcccdeaaa", the answer is "abcdea".*/
 char* rem1(char* s) {
  if(strlen(s)==0){
    return s;
  }
  char* str1;
  str1 = (char*)malloc(strlen(s)+1);
  if(s[0]==s[1]){
    return rem1(s+1);
  }
  else{
    str1[0] = s[0];
    str1[1] = '\0';
    return strcat(str1,rem1(s+1));
  }
}


/** = number of the digits in the decimal representation of n.
e.g. numDigits(0) = 1, numDigits(3) = 1, numDigits(34) = 2.
numDigits(1356) = 4.
Precondition: n >= 0. */
int numDigits(int n) {
  if(n<0){
    return 0;
  }
  if(n/10==0){
    return 1;
  }
	return 1+numDigits(n/10);
}

/** = sum of the digits in the decimal representation of n.
e.g. sumDigits(0) = 0, sumDigits(3) = 3, sumDigits(34) = 7,
sumDigits(345) = 12.
Precondition: n >= 0. */
int sumDigits(int n) {
  if (n / 10 == 0) {
  	return n;
  }
  return (n % 10) + sumDigits(n / 10);

}

/** = a copy of s with to_remove_char removed.
Example: removeChar("abeabe", 'e') = "abab". */
char* removeChar(char* s, char to_remove_char) {
  if(strlen(s)==0){
    return s;
  }
  char* str1;
  str1 = (char*)malloc(strlen(s)+1);
  if(s[0]==to_remove_char){
    return removeChar(s+1,to_remove_char);
  }
  else{
    str1[0] = s[0];
    str1[1] = '\0';
    return strcat(str1,removeChar(s+1,to_remove_char));
  }
}

/** = a copy of s with characters in reverse order.
Example: reverse("abcdefg") = "gfedcba". */
char* reverse(char* s) {
  if(strlen(s)==0){
    return s;
  }
  char* str1;
  char* str2;
  str1 = (char*)malloc(strlen(s)+1);
  str2 = (char*)malloc(strlen(s)+1);
  str1[0]=s[0];
  str1[1]='\0';
  str2[0]='\0';
  // printf("%s\n",str1 );
  return strcat(strcat(str2,reverse(s+1)),str1);
}


int main() {
	char s1[] = "aaabbbaccabda";
  printf("%d\n",numberNotc('c',s1));
  printf("%s\n",replace(s1,'a','z'));
  printf("%d\n",numDigits(5423));
  printf("%d\n",sumDigits(543));
  printf("%s\n",rem1("aabbccddd"));
  printf("%s\n",removeChar("aabbccddd",'a'));
  printf("%s\n",reverse("abcdef"));
	return 0;
}
