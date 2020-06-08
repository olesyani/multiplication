#ifndef mult_h
#define mult_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct int_long {
    char * data;
    int size;
} INT_LONG;

void Timer(void);
void PrintString(INT_LONG str);
void Clean(INT_LONG num);
char IsBigger(INT_LONG num1, INT_LONG num2); //which number is bigger
INT_LONG RandString(int size); //randomizing long numbers
INT_LONG Addition(INT_LONG num1, INT_LONG num2); //addition of long numbers alg
INT_LONG Subtraction(INT_LONG num1, INT_LONG num2); //subtraction alg
INT_LONG NaiveMultiplication(INT_LONG num, char n, int pos); //inside of naive mult alg
INT_LONG Naive(INT_LONG num1, INT_LONG num2); //naive multiplication alg
INT_LONG Grid(INT_LONG num1, INT_LONG num2); //grid alg
INT_LONG Divide(INT_LONG num, int first, int last); //splitting numbers for simple DNC & karatsuba algs
INT_LONG MakeEqual(INT_LONG num1, INT_LONG num2); //making digits of two numbers equal
INT_LONG ExtraDigits(INT_LONG num, int n); //extra digits '0'
INT_LONG DeleteZero(INT_LONG num); //delete extra zeros
INT_LONG SimpleDNC(INT_LONG num1, INT_LONG num2); //simple DNC alg
INT_LONG Karatsuba(INT_LONG num1, INT_LONG num2); //karatsuba alg
#endif
