#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_STRUCTS 100


typedef struct
{
    char firstName[MAX_NAME];
    char lastName[MAX_NAME];
    int age;
} person;

int read_txt_file(person tmpPeople[], char fileName[]) {
    FILE *fp;
    int num = 0, tmpAge;
    char fName[MAX_NAME], lName[MAX_NAME];

    if((fp = fopen(fileName, "r")) == NULL) {
        printf("Error while opening %s\n", fileName);
        exit(1);
    }

    // perform reading operations
    printf("\n | Read txt file: %s\n", fileName);
    while( fscanf(fp, "%s %s %d\n", fName, lName, &tmpAge) != EOF )
    {
        stpcpy(tmpPeople[num].firstName, fName);
        stpcpy(tmpPeople[num].lastName, lName);
        tmpPeople[num].age = tmpAge;

        printf("%d| %s %s %d\n", num, tmpPeople[num].firstName, tmpPeople[num].lastName, tmpPeople[num].age);
        num++;
    }

    if(fclose(fp) != 0) {
        printf("Error: wrong file closure!\n");
        exit(2);
    }

    return num;
}

int read_bin_file(person tmpPeople[], char fileName[]) {
    FILE *fp;
    int num;

    int tmpAge;
    char fName[MAX_NAME], lName[MAX_NAME];

    if((fp = fopen(fileName, "rb")) == NULL) {
        printf("Error while opening %s\n", fileName);
        exit(1);
    }

    // perform reading operations
    printf("\n | Read bin file: %s\n", fileName);
    num = fread(tmpPeople, sizeof(person), MAX_STRUCTS, fp);
    
    for(int i = 0; i < num; i++) {
        printf("%d| %s %s %d\n", i, tmpPeople[i].firstName, tmpPeople[i].lastName, tmpPeople[i].age);
    }

    if(fclose(fp) != 0) {
        printf("Error: wrong file closure!\n");
        exit(2);
    }

    return num;
}

void write_person_to_bin(person tmpPerson, char fileName[]) {
    FILE *fp;

    if((fp = fopen(fileName, "ab")) == NULL) {
        printf("Error while opening %s\n", fileName);
        exit(1);
    }

    // perform writing operations
    printf("Write person to bin: %s\n", tmpPerson.firstName);
    fwrite(&tmpPerson, sizeof(person), 1, fp);
    // fwrite(tmpPerson.firstName, sizeof(char [MAX_NAME]), 1, fp);
    // fwrite(tmpPerson.lastName, sizeof(char [MAX_NAME]), 1, fp);
    // fwrite(&tmpPerson.age, sizeof(int), 1, fp);

    if(fclose(fp) != 0) {
        printf("Error: wrong file closure!\n");
        exit(2);
    }
}

void write_person_to_txt(person tmpPerson, char fileName[]) {
    FILE *fp;

    if((fp = fopen(fileName, "at")) == NULL) {
        printf("Error while opening %s\n", fileName);
        exit(1);
    }

    // perform writing operations
    printf("Write person to txt: %s\n", tmpPerson.firstName);
    fprintf(fp, "%s ", tmpPerson.firstName);
    fprintf(fp, "%s ", tmpPerson.lastName);
    fprintf(fp, "%d\n", tmpPerson.age);

    if(fclose(fp) != 0) {
        printf("Error: wrong file closure!\n");
        exit(2);
    }
}

void write_to_txt_line_by_line(person tmpPeople[], int peopleL, char fileName[]) {
    for(int i = 0; i < peopleL; i++) {
        printf("Write to txt line by line. Person n %d\n", i);
        write_person_to_txt(tmpPeople[i], fileName);
    }
}

void write_to_bin_line_by_line(person tmpPeople[], int peopleL, char fileName[]) {
    for(int i = 0; i < peopleL; i++) {
        printf("Write to bin line by line. Person n %d\n", i);
        write_person_to_bin(tmpPeople[i], fileName);
    }
}

int main() {
    person people[MAX_STRUCTS];
    person peopleBin[MAX_STRUCTS];
    int dim, dimBin;

    dim = read_txt_file(people, "anagrafe.txt");
    write_to_bin_line_by_line(people, dim, "anagrafe.bin");
    dimBin = read_bin_file(peopleBin, "anagrafe.bin");
    write_to_txt_line_by_line(peopleBin,dimBin, "copy-anagrafe.txt");

    printf("\n\nPeople\n");
    for(int i = 0; i < dim; i++) {
        printf("%d\t%s - %s - %d\n", i, people[i].firstName, people[i].lastName, people[i].age);
    }

    printf("\n\nBin People\n");
    for(int i = 0; i < dimBin; i++) {
        printf("%d\t%s - %s - %d\n", i, peopleBin[i].firstName, peopleBin[i].lastName, peopleBin[i].age);
    }
    
    return 0;
}

// cd files/read-write-es
// rm anagrafe.bin && rm copy-anagrafe.txt && gcc -o main main.c && ./main
// cat copy-anagrafe.txt

/*
Create anagrafe.txt file and insert as many person as you want.

1. read the people from the anagrafe.txt file
2. write each person to anagrafe.bin file
3. read people from anagrafe.bin file
4. write each person to copy-anagrafe.txt file
5. print people read from both files 
*/