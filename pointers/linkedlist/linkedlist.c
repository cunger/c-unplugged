/*
 * Linked List
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node * next;
};

typedef struct node node;
typedef node * linkedlist;

void pretty_print(linkedlist list) {
  printf("{");

  linkedlist current = list;
  while (current) {
    printf("%d", current->data);

    if (current->next) {
      printf(", ");
    }

    current = current->next;
  }

  printf("}\n");
}

linkedlist init_linked_list() {
  return NULL;
}

void add(linkedlist * p_list, int element) {
  node new_node = { element, NULL };

  if (*p_list == NULL) {
    *p_list = &new_node;
  } else {
    linkedlist last = *p_list;
    while (last) {
      last = last->next;
    }

    (*last).next = &new_node;
  }
}

int length(linkedlist list) {
  int count = 0;

  linkedlist current = list;
  while (current) {
    ++count;
    current = current->next;
  }

  return count;
}

int main() {
  node third  = { 3, NULL };
  node second = { 2, &third };
  node first  = { 1, &second };

  linkedlist numbers = &first;

  pretty_print(numbers);
  printf("length: %d\n", length(numbers));

  linkedlist numbers_again = init_linked_list();

  pretty_print(numbers_again);
  printf("length: %d\n", length(numbers_again));

  add(&numbers_again, 1);
  add(&numbers_again, 2);

  pretty_print(numbers_again);
  printf("length: %d\n", length(numbers_again));

  return 0;
}
