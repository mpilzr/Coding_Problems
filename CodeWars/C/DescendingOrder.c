/*    INSTRUCTIONS:

Your task is to make a function that can take any non-negative integer as an argument and return it with its digits in descending order.
Essentially, rearrange the digits to create the highest possible number.
Examples:

Input: 42145 Output: 54421

Input: 145263 Output: 654321

Input: 123456789 Output: 987654321
*/

#include <inttypes.h>
#include <stdio.h>



int compareDigits(const void* a, const void* b) {return (*(int*)b - *(int*)a);}

void swap(void* a, void* b, size_t size) {
  char temp[size];
  memcpy(temp, a, size);
  memcpy(a, b, size);
  memcpy(b, temp, size);
}

void qsort(void* base, size_t num, size_t size, int (*compar)(const void*, const void*)){ //Quicksort function.
  if(num <= 1) {return;}
  char* pivot = (char*)base + (num - 1) * size;
  char* i = (char*)base - size;
  for (char* j = (char*)base; j != pivot; j += size) {
    if (compar(j, pivot) <= 0) {
      i += size;
      swap(i, j, size);
    }
  }
  i += size;
  swap(i, pivot, size);
  size_t index = (i - (char*)base) / size;
  qsort(base, index, size, compar);
  qsort(i + size, num - index - 1, size, compar);
}


uint64_t descendingOrder(uint64_t n) {
  int digitnum = 0;
  uint64_t temp = n;
  while (temp != 0) {
    temp /= 10;
    digitnum++; 
  }
  int digits[digitnum];
  for (int i = digitnum - 1; i >= 0; i--) {
    digits[i] = n % 10;
    n /= 10;
  }
  qsort(digits, digitnum, sizeof(int), compareDigits);
  uint64_t result = 0;
  for (int i = 0; i < digitnum; i++) {
    result = result * 10 + digits[i];
  }
  return result;
}