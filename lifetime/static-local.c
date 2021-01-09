#include <stdio.h>

void function() {
    // static local
    static int staticLocal = 10;

    // automatic local
    int autoLocal = 10;
    printf("static local = %d, automatic local = %d\n", staticLocal, autoLocal);
    
    // increase the value of the variables
    staticLocal++;
    autoLocal++;
}

int main() {
    function();
    function();
    function();

    return 0;
}

// cd lifetime
// gcc -o sl static-local.c && ./sl