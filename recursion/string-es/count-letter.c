#include <stdio.h>
#include <stdlib.h>

int iterative_count_letter(char word[], char letter) {
    int i = 0;
    int res = 0;

    while(word[i] != '\0') {
        if(word[i] == letter) {
            res++;
        }
        
        i++;
    }

    /*
    for (i = 0; i < strlen(word); i++) {
        printf("%c\n", word[i]);
    }
    */

    return res;
}

int tail_recursive_count_letter(char word[], char letter, int iterative, int result) {
    int i = iterative;
    int res = result;

    if(word[i] != '\0') {
        if(word[i] == letter) {
            res++;
        }
        
        i++;

        return tail_recursive_count_letter(word, letter, i, res); 
    }

    return res;
}

int main() {
    char s[] = "alpha";
    char l = 'a';

    int iterRes = iterative_count_letter(s, l);
    int tailRes = tail_recursive_count_letter(s, l, 0, 0);

    printf("In the word \"%s\", \"%c\" appear %d times.\n", s, l, iterRes);
    printf("In the word \"%s\", \"%c\" appear %d times.\n", s, l, tailRes);

    return 0;
}

// cd recursion/string-es
// gcc -o count-letter count-letter.c && ./count-letter