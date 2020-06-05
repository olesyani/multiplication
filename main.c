#include <stdio.h>
#include "multiplication.h"

int main() {
    char a[256],b[256];
    gets(a); //нужен аналог
    gets(b);
    dnc_helper(a, b);
    return 0;
}
