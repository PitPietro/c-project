#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME 20
#define MAX 6
#define ADDR 50
const char fileName[] = "SALARY.bin";

typedef struct {
    char firstName[NAME];
    char lastName[NAME];
    int age;
    // TODO: Add the department with an Enum
    int salary;
} person;

void print_people(person p[], int num) {
    for(int i = 0; i < num; i++) {
        printf("%s %s - age: %d - salary: %d\n", p[i].firstName, p[i].lastName, p[i].age, p[i].salary);
    }
}

void write_bin(person p[]) {
    int i;
    FILE *fp;

    // open file
    if((fp = fopen(fileName, "wb")) == NULL) {
        exit(1);
    }

    // write
    i = fwrite(p, sizeof(person), MAX, fp);

    if(i != MAX) {
        exit(3);
    }

    // close
    if(fclose(fp) != 0) {
        exit(2);
    }
}

int read_bin(person p[]) {
    int i;
    FILE *fp;

    // open file
    if((fp = fopen(fileName, "rb")) == NULL) {
        exit(1);
    }

    // read
    i = fread(p, sizeof(person), MAX, fp);

    // close
    if(fclose(fp) != 0) {
        exit(2);
    }

    return i;
}

void apply_salary_increase(person p[]) {
    // increase the salary if it's lower than 10'000
    int i = 0;
    FILE *fp;

    // open file
    if((fp = fopen(fileName, "r+b")) == NULL) {
        exit(1);
    }

    while(fread(&p[i], sizeof(person), 1, fp) == 1) {
        if(p[i].salary < 10000) {
            p[i].salary = p[i].salary + (p[i].salary/10);
            fseek(fp, -(long)sizeof(person), SEEK_CUR);

            fwrite(&p[i], sizeof(person), 1, fp);

            fseek(fp, 0, SEEK_CUR);
        }

        i++;
    }

    // close
    if(fclose(fp) != 0) {
        exit(2);
    }
}

int main() {
    person employees[MAX] = {
        {"Philip Jay", "Fry", 34, 12000},
        {"Turanga","Leela", 25, 8000},
        {"Hubert J.", "Farnsworth", 150, 5000},
        {"Hermes", "Conrad", 56, 5000},
        {"Doctor", "Zoidberg", 44, 15450},
        {"Zapp", "Brannigam", 61, 4000}
    };
    person newE[MAX];
    int n;

    print_people(employees, MAX);
    printf("______________________________\n");
    write_bin(employees);
    n = read_bin(newE);
    print_people(newE, n);
    apply_salary_increase(newE);
    printf("______________________________\n");
    print_people(newE, n);
    
    return 0;
}

// cd files/fseek/exercises/salary-increase-es
// gcc -o main main.c && ./main