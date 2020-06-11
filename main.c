#include "mult.h"

int main() {
    int size1, size2, n;
    double t1 = 0, t2 = 0, t3 = 0, s;
    srand(time(NULL));
    puts("How many digits should be in the first number?");
    scanf("%d", &size1);
    puts("How many digits should be in the second number?");
    scanf("%d", &size2);
    puts("How many tests do you want?");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        INT_LONG NUM1, NUM2, A;
        NUM1 = RandString(size1);
        NUM2 = RandString(size2);
        
        s = clock();
        A = Naive(NUM1, NUM2);
        t1 += (clock() - s) / CLOCKS_PER_SEC;
        
        s = clock();
        A = Karatsuba(NUM1, NUM2);
        t2 += (clock() - s) / CLOCKS_PER_SEC;
        
        s = clock();
        A = Grid(NUM1, NUM2);
        t3 += (clock() - s) / CLOCKS_PER_SEC;
    }
    t1 /= n;
    t2 /= n;
    t3 /= n;
    printf("naive: %f sec\n", t1);
    printf("karatsuba: %f sec\n", t2);
    printf("grid: %f sec\n", t3);
    return 0;
}
