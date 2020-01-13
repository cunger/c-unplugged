#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
  double random =  (double) rand() / (double) ((unsigned) RAND_MAX + 1);
  printf("%f\n", random);

  int i = random < 0.5 ? 1 : 0;
  printf("%d\n", i);

  return 0;
}
