#include <stdio.h>

// There is no bool. int 0 is false, int 1 is true.

#ifndef __cpluplus
typedef char bool;
#define true 1
#define false 0
#endif

int main() {
  bool whoop = false;

  if (whoop) {
    printf("%f\n", 3.14);
  } else {
    printf("%d\n", 23); // using float as second argument will get you into a mess
  }

  return 0;
}
