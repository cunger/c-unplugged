#include <stdio.h>

/* The builtin strcpy function has signature (char * dest, const char * source). */
void stringcopy(char dest[], const char source[]) {
  int i = 0;

  while (source[i] != '\0') {
    dest[i] = source[i];
    i++;
  }

  dest[i] += '\0';
}

int main() {
  char original[] = "Fnord!"; // char original[] = {'F', 'n', 'o', 'r', 'd', '!', '\0'};
  char copy[7];               // Note that you have to count \0 as well!

  stringcopy(copy, original);

  printf("%s\n", copy);

  return 0;
}
