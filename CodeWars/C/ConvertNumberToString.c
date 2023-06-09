/*      INSTRUCTIONS:

We need a function that can transform a number (integer) into a string.

What ways of achieving this do you know?

In C, return a dynamically allocated string that will be freed by the test suite.
Examples (input --> output):

123  --> "123"
999  --> "999"
-100 --> "-100"
*/

#include <stdlib.h>
#include <stdio.h>


char *number_to_string(int num){
    int length = snprintf(NULL, 0, "%d", num);
    char* str = (char*)calloc(length + 1, sizeof(char));
    snprintf(str, length + 1, "%d", num);
    return str;
}
