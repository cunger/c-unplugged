/*
 * Unions are structures where the elements share the starting address
 * in memory, so they take up as much space as the largest element
 * (i.e. the amount of space required to hold any of its elements).
 *
 * They are declared in a separate namespace, like structures and enumerations.
 */

#include <stdio.h>

typedef unsigned char byte;

 typedef union {
   byte FIRST;
   byte SECOND;
 } something;

 int main() {
   something x;

   x.FIRST  = '1';
   x.SECOND = '0';

   printf("something FIRST = %c, SECOND = %c\n", x.FIRST, x.SECOND);

   return 0;
 }
