#include <stdio.h>

typedef unsigned char byte;

/*   signed char -> signed 8-bit with range like -128..127 */
/* unsigned char -> unsigned 8-bit with range like 0..255  */

int main() {
  int i = 42000;
  float f = 3.14f;
  double d = 3.14;

  char c = 'c';
  char * s = "Fnord!";

  byte b = 0x12;

  short int si = 1;
  long int li = 325433249868756;

  unsigned int ui = 1u;

  printf("%d (%d)\n",   i, (int) sizeof(int));          // 4 bytes (32 bits)
  printf("%d (%d)\n",  ui, (int) sizeof(unsigned int)); // 4 bytes (32 bits)
  printf("%d (%d)\n",  si, (int) sizeof(short int));    // 2 bytes (16 bits)
  printf("%ld (%d)\n", li, (int) sizeof(long int));     // 8 bytes (64 bits)

  printf("%f (%d)\n",   f, (int) sizeof(float));        // 4 bytes (32 bits)
  printf("%f (%d)\n",   d, (int) sizeof(double));       // 8 bytes (64 bits)
  
  /* The size of char is defined to be exactly 1 byte, the smallest
     addressable  unit on the computer. So sizeof(char) is always 1. */

  printf("%c (%d)\n",   c, (int) sizeof(char));         // 1 byte  (8 bits)
  printf("%c (%d)\n",   b, (int) sizeof(byte));         // 1 byte  (8 bits)
  printf("%s (%d)\n",   s, (int) sizeof(char *));       // 8 bytes (64 bits)

  return 0;
}
