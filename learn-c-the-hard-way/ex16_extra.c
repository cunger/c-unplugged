#include <stdio.h>
#include <string.h>

struct Person {
  char * name;
  int age;
};

struct Person create_person(char * name, int age) {
  struct Person person = { name, age };
  return person;
}

void print_person(struct Person person) {
  printf("Name: %s\n", person.name);
  printf(" Age: %d\n", person.age);
}

int main() {
  struct Person joe = create_person("Joe Alex", 32);
  struct Person frank = create_person("Frank Blank", 20);

  print_person(joe);
  print_person(frank);

  printf("10 years later...\n");

  joe.age += 10;
  frank.age += 10;

  print_person(joe);
  print_person(frank);

  return 0;
}
