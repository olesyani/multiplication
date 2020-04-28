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

INT_LONG RandString(int size);
INT_LONG Addition(INT_LONG num1, INT_LONG num2);
INT_LONG Subtraction(INT_LONG num1, INT_LONG num2);
INT_LONG NaiveMULT(INT_LONG num, char n, int pos);
INT_LONG SimpleDNC(INT_LONG num1, INT_LONG num2);
INT_LONG Divide(INT_LONG res, INT_LONG num, int first, int last);
INT_LONG KarDNC(INT_LONG num1, INT_LONG num2);
void Naive(INT_LONG num1, INT_LONG num2);
void PrintStr(INT_LONG str);
#endif
