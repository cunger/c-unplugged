/*
Linked List
*/

struct node {
  int data;
  struct node * next;
};

typedef struct node node;
typedef node * linkedlist;

node * init(int element);
void add(linkedlist * list, int element);
void destroy(linkedlist * list);

int length(linkedlist list);
node * last(linkedlist list);

void pretty_print(linkedlist list);
