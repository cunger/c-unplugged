#include <stdio.h>

/*
 * Enumerations are sequences of named integer constants.
 *
 * They are declared in a separate namespace, like structures and unions.
 */

 enum BOOLEAN {
   false, // = 0
   true   // = 1
 };

/* Changing default values, and in combination with typedef: */
typedef enum {
  club = 0,
  spades = 3,
  diamonds = 10,
  hearts = 20
} suit;

/* Declaring a variable with an unnamed enum type: */
enum { no, yes } response;

int main() {
  int test1 = (true  && true)  == 1;
  int test2 = (true  && false) == 0;
  int test3 = (false && true)  == 0;
  int test4 = (false && false) == 0;
  int test5 = (true  || true)  == 1;
  int test6 = (true  || false) == 1;
  int test7 = (false || true)  == 1;
  int test8 = (false || false) == 0;

  printf("%d %d %d %d %d %d %d %d\n",
    test1,
    test2,
    test3,
    test4,
    test5,
    test6,
    test7,
    test8);

  printf("score: %d\n", hearts + 2 * diamonds);

  return 0;
}
