#include <stdio.h>

/*
  Determing the length of a C-style string,
  not counting the trailing '\0'.
*/
int length(const char string[]) {
  int i = 0;

  while (string[i] != '\0') {
    i++;
  }

  return i;
}

/*
  A custom implementation of the builtin strcpy function.
  Note that strcpy has the following signature instead:
  void strcpy(char * dest, const char * source)
*/
void stringcopy(char dest[], const char source[]) {
  int i;

  for (i = 0; source[i] != '\0'; i++) {
    dest[i] = source[i];
  }

  dest[i] += '\0';
}

/*
  A version that creates the copy inside the function
  instead of passing it as an argument. This does not
  work, as `dest` is a pointer to a local address,
  which exists only as long as the function lives.
  So the returned pointer points to an invalid address
  once the function exits.
*/
char * create_copy(const char source[]) {
  char dest[length(source) + 1];

  stringcopy(dest, source);

  return dest;
}

int main() {
  char original[] = "Fnord!";
  char dest[7];

  /*
  Strings are arrays of characters, ending with the null character '\0'
  (which is a character with all bits set to zero). Thus,

      char original[] = "Fnord!";

   is the same as:

      char original[] = {'F', 'n', 'o', 'r', 'd', '!', '\0'};

   So when allocating memory for such a string, you have to count the
   trailing null charater as well (dest[7] instead of dest[6]).
   */

  stringcopy(dest, original);

  printf("%s\n", dest);
  printf("%d\n", length(original));

  return 0;
}
