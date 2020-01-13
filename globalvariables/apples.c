static int data;
// global variable; is initialized to 0
// without 'static', will be shared with `data` in oranges.c

void set_apples(int value) {
  data = value;
}

int get_apples() {
  return data;
}
