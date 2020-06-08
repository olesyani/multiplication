#include <stdio.h>
#include "multiplication.h"
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int c,d;
    c = rand()%11;
    d = rand()%11;
    char *a = (char*)calloc(c+1,sizeof(char));
    char *b = (char*)calloc(d+1,sizeof(char));
    a[0] = 49+rand()%9;
    b[0] = 49+rand()%9;
    printf("%c",a[0]);
    for(int i = 1;i<c;i++) {
        a[i] = 48+rand()%10;
        printf("%c",a[i]);
    }
    printf("\n");
    printf("%c",b[0]);
    for(int i = 1;i<d;i++) {
        b[i] = 48+rand()%10;
        printf("%c",b[i]);
    }
    printf("\n%s\n",native(a,b));
    return 0;
}
