#include "mult.h"

int main() {
    int size1, size2;
    INT_LONG NUM1, NUM2, A;
    
    srand(time(NULL));
    
    scanf("%d%d", &size1, &size2);
    NUM1 = RandString(size1);
    NUM2 = RandString(size2);
    
    clock_t s = clock();
    A = Naive(NUM1, NUM2);
    double t = (clock() - s) / CLOCKS_PER_SEC;
    puts("NAIVE:");
    PrintString(A);
    Clean(A);
    printf("The time is %f sec\n", t);
    
    s = clock();
    A = Grid(NUM1, NUM2);
    t = (clock() - s) / CLOCKS_PER_SEC;
    puts("GRID:");
    PrintString(A);
    Clean(A);
    printf("The time is %f sec\n", t);

    s = clock();
    A = SimpleDNC(NUM1, NUM2);
    t = (clock() - s) / CLOCKS_PER_SEC;
    puts("SIMPLE DNC:");
    PrintString(A);
    Clean(A);
    printf("The time is %f sec\n", t);
    
    s = clock();
    A = Karatsuba(NUM1, NUM2);
    t = (clock() - s) / CLOCKS_PER_SEC;
    puts("KARATSUBA:");
    PrintString(A);
    Clean(A);
    printf("The time is %f sec\n", t);
    return 0;
}
