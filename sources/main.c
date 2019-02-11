#include <stdio.h>
#include "commons.h"

void print_arguments(int argc, char * argv[]);

/*
  Example:
  $ gcc *.c
  $ ./a.out arg1 arg2 "arg3 with spaces"
*/
int main(int argc, char * argv[]) {
  print_arguments(argc, argv);

  blah();
  fnord();

  return 0;
}

void print_arguments(int argc, char * argv[]) {
  printf("Function name: %s\n", argv[0]);

  printf("Arguments:");

  int i;
  for (i = 1; i < argc; i++) {
    printf(" %s", argv[i]);
    if (i < argc - 1) {
      printf(",");
    }
  }

  printf("\n");
}
