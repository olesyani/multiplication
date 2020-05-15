#ifndef mult_h
#define mult_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct int_long {
    char * data;
    int size;
} INT_LONG;

void PrintStr(INT_LONG str);
void Clean(INT_LONG num);
INT_LONG RandString(int size); //randomizing long numbers
INT_LONG Addition(INT_LONG num1, INT_LONG num2); //addition of long numbers alg
INT_LONG Subtraction(INT_LONG num1, INT_LONG num2); //subtraction alg
INT_LONG NaiveMULT(INT_LONG num, char n, int pos); //inside of naive mult alg
INT_LONG Naive(INT_LONG num1, INT_LONG num2); //naive multiplication alg
INT_LONG Divide(INT_LONG num, int first, int last); //splitting numbers for simple DNC & karatsuba algs
INT_LONG SimpleDNC(INT_LONG num1, INT_LONG num2); //simple DNC alg
INT_LONG KaratsubaDNC(INT_LONG num1, INT_LONG num2); //karatsuba alg
#endif
