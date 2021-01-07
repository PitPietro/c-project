#define THRESHOLD 100
#define NAME 10
#define MAX 5

typedef struct {
    char name[NAME];
    int price;
} product;

void print_products(product [], int);
void fake_insert_products(product []);
void write_bin(product []);
int read_bin(product []);
void apply_discount(product []);