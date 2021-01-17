#define CITY 10
#define NAME 20
#define TIME 11
#define MAX 15
#define ADDR 50

// it contains the fields of a temperature record
typedef struct {
    double value; // temperature value
    unsigned short int day; // 1 - 7 (monday - sunday) it could become an Enum
    char city[CITY];
    char time[TIME]; // format: dd/MM/yyyy (m = minute, M = month)
} temperature;

void print_temps(temperature[], int);