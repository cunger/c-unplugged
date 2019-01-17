#include <stdio.h>

/* Preprocessor will replace every occurence of the constant
   with the respective value. */
#define MIN 0
#define MAX 100
#define STEP 2

void whoop() {
  /* Re-initialized every time the function is called. */
  int eggs = 4;

  /*
   * Retains its value between function invocations (see main below),
   * because it's stored in the statically allocated memory instead of
   * the automatically allocated one.
   * Needs to be constant at compile time, e.g. the following doesn't compile:
   *     static int hens = eggs;
   */
  static int hens = 4;

  eggs += 1;
  hens += 1;

  printf("%d %d\n", eggs, hens);
}

int main() {
  int i;

  for (i = MIN; i <= MAX; i += STEP) {
    printf("%d ", i);
  }

  printf("\n");

  whoop(); // 5 5
  whoop(); // 5 6
  whoop(); // 5 7

  return 0;
}
