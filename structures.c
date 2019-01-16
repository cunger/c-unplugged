struct color {
  float red;
  float green;
  float blue;
  float alpha;
};

struct color c1 = { 1, 0, 0, 1 };

typedef struct {
  int code;
  char message[256];
} error;

error e = { 404, "Not found" };

int main() {
  return 0;
}
