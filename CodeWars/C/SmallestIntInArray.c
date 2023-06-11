/*      INSTRUCTIONS
    Given an array of integers your solution should find the smallest integer.

    For example:

    Given [34, 15, 88, 2] your solution will return 2
    Given [34, -345, -1, 100] your solution will return -345

    Assume the array is not empty.
*/

#include <stddef.h>

int find_smallest_int(const int array[/* len */], size_t len){
  int min = array[0];
  for(size_t i =  1 ; i < len ; i++){
    if(array[i] < min){min = array[i];}
  } return min;
}