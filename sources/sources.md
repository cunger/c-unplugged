C is a compiled language.

Files:
* `.c` source file
* `.h` header file (declarations to be shared among source files)

## Example

See `main.c`:

```c
#include "commons.h"
/* Not parsed by the compiler.
 * The preprocessor will replace this by the content of commons.h,
   which thus includes the required function declarations in main.c. */

int main() {
  fnord();

  return 0;
}
```

In order to compile, run GCC on all source files:
```
$ gcc blah.c fnord.c main.c
```
Or:
```
$ gcc *.c
```

Running only the GCC preprocessor:
```
$ gcc -E main.c
```

Using `make` for compiling and linking:
```
$ make main
cc main.c -o main
```

Or with options:
```
$ CFLAGS="-Wall" make main
cc -Wall main.c -o main
```
