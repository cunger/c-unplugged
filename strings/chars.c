#include <stdio.h>

int main(void) {
  char null_byte = '\0';

  printf("%c\n", null_byte);
  printf("%s\n", null_byte); // warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int’

  char name[10] = { 'c' }; // uninitialized values in an array will be 0
  char other_name[] = { 'f', 'r', 'e', 'd' }; // misses the final '\0'

  printf("name: %s\n", name);
  printf("name: %s\n", other_name); // so this will print an extra char (the one that's still on the stack? in this case 'c')
}
