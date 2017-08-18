#include "stdio.h"
#include "stdlib.h"
int movement[10][3] = {{4,6,-1},{6,8,-1},{7,9,-1},{4,8,-1},{0,3,9},{-1,-1,-1},{0,1,7},{2,6,-1},{1,3,-1},{2,4,-1}};
int numMove[10] = {2,2,2,2,3,0,3,2,2,2};
void f(int n) {
  if (n <= 0) return;
  f(n-1);
  printf("%d", n);
  f(n-1);
}
int sumBinary(int num) {
  if (num <= 0) {
    return 0;
  }
  if(num%2==0){
    return sumBinary(num/2);
  }else{
    return 1+sumBinary(num/2);
  }
}

int temp[7];
int count = 0;
void explore_ways(int start_node, int acc) {
  temp[acc] = start_node;
  if (acc == 7) {
    printf("%d%d%d%d%d%d%d\n",temp[1],temp[2],temp[3],temp[4],temp[5],temp[6],temp[7]);
    count++;
    return;
  }
  for(int i=0; i<numMove[start_node]; i++) {
    // temp[acc] = movement[start_node][i];
    // printf("%d",movement[start_node][i]);
    explore_ways(movement[start_node][i], acc+1);
  }
}



// int duplicate(char* num){
//   if(strlen(num)==0){
//     return 1;
//   }
// }

// void permute(char* s) {
//   if (strlen(s) <= ) {
//     printf("%s\n", s);
//     return;
//   }
//   for (int i = 0; i < strlen(s); i++) {
//     char* prefix = malloc(1);
//     prefix[0] = s[i]
//     char* suffix = malloc(strlen(s) - 1)
//     strcpy(suffix, s);
//     suffix[i] = '';
//     permute(strcat(prefix, suffix));
//   }
//   printf("%s", s);
// }

int main(){
  f(5);
  printf("\n");
  printf("%d\n", sumBinary(14));
  // permute("ab");
  char * pnum;
  // for (int i=0; i<10; i++) {
  //   phone(pnum, 1,0);
  // }
  for (int i=0; i<10; i++) {
    explore_ways(i, 1);
  }
  printf("Number of valid number : %d\n",count );
}
