#include "mult.h"

int main() {
    int size1, size2;
    INT_LONG NUM1, NUM2, A;
    
    srand(time(NULL));
    
    scanf("%d%d", &size1, &size2);
    
    NUM1 = RandString(size1);
    NUM2 = RandString(size2);
    
    Naive(NUM1, NUM2);
    
    A = SimpleDNC(NUM1, NUM2);
    puts("SIMPLE DNC:");
    PrintStr(A);
    
    A = KarDNC(NUM1, NUM2);
    puts("KARATSUBA:");
    PrintStr(A);
    return 0;
}
