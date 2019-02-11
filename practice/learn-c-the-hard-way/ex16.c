#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char * name;
  int age;
};

struct Person * create_person(char * name, int age) {
  struct Person * person = malloc(sizeof(struct Person));
  assert(person != NULL);

  person->name = strdup(name);
  person->age = age;

  return person;
}

void destroy_person(struct Person * person) {
  assert(person != NULL);

  free(person->name);
  free(person);
}

void print_person(struct Person * person) {
  printf("Name: %s\n", person->name);
  printf(" Age: %d\n", person->age);
}

int main() {
  struct Person * joe = create_person("Joe Alex", 32);
  struct Person * frank = create_person("Frank Blank", 20);

  printf("joe is at memory location %p\n", joe);
  print_person(joe);

  printf("frank is at memory location %p\n", frank);
  print_person(frank);

  printf("10 years later...\n");

  joe->age += 10;
  frank->age += 10;

  print_person(joe);
  print_person(frank);

  destroy_person(joe);
  destroy_person(frank);

  return 0;
}
