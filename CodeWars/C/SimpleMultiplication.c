/*      INSTRUCTIONS:
    This problem is about multiplying a given number by eight if it is an even number and by nine otherwise.
*/

int simple_multiplication(int n){
    if(n % 2 == 0){return n * 8;}
    return n * 9;
}