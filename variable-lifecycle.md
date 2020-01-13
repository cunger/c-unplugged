A local variable exists only as long as the function where it is declared is still executing.

## static

## const

Using `const` to qualify a function parameter shows that the function will not change the passed argument,
which is helpful intention showing when pointers are passed.
For example:

```c
void fnord(const struct node * n);
```

## Call-by-value vs call-by-reference

Arguments are passed by value, i.e. argument values are copied into local storage that exists
only until the function exits.

This means, for example, that when a `struct` is passed, changes to it inside the function body
affect only the copy, not on the original structure. Also, call-by-value can be undesirable
when the argument value is large.

Call-by-reference can be achieved by passing a pointer.
