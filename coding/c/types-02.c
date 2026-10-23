#include <stdio.h>
#include <stdint.h>

typedef int8_t i8;

int main(){

  int a = 1;              
  i8 b = 1;

  printf("ints: a = %d, b = %d\n", a, b);
  printf("sizes: a = %zu bytes, b = %zu bytes\n", sizeof(a), sizeof(b));

  return 0;
} 
