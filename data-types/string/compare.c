#include <stdio.h>
#include <string.h>

#define DIM 50

int main () {
  // char *str1 = "foo";
  // char *str2 = "bar";

  char str1[20];
  char str2[20];

  printf("insert 1st string: ");
  scanf("%s", str1);

  printf("insert 2nd string: ");
  scanf("%s", str2);
  
  int result;

  result = strcmp(str1, str2);

  printf("\n");

  if(result > 0) {
    printf("str1 is longer");
  } else if(result < 0) {
    printf("str2 is longer");
  } else {
    printf("The two strings are equal");
  }

  printf("\n");

  return(0);
}

// cd data-types/string
// gcc -o cmp compare.c && ./cmp