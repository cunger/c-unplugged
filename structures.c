/*
 * Structures are sequences of variables (of any type).
 * For memory usage of sequences, look up padding.
 */

struct color {
  float red;
  float green;
  float blue;
  float alpha;
};

/*
 * The C compiler puts structs into an own namespace,
 * so when referencing them, they need to be looked up there:
 */

struct color c1 = { 1, 0, 0, 1 };

/* Alternative: use a type definition */

typedef struct color color;

color c2 = { 0, 0, 0, 1 };

/* Or directly when defining the structure
 * (presupposed the type synonym doesn't clash with another variable
 * or function name): */

typedef struct {
  int code;
  char message[256];
} error;

error e = { 404, "Not found" };

int main() {
  return 0;
}
