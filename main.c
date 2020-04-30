#include <stdio.h>
#include "multiplication.h"

int main() {
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("Native: %d\n",native(a,b));
    printf("DnC: %d\n",dnc(a,b));
    printf("Karatsuba: %d\n",karatsuba(a,b));
    return 0;
}
