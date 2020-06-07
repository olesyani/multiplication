//
// Created by Nikita on 18.05.2020.
//

#ifndef DNC_MULTIPLICATION_H
#define DNC_MULTIPLICATION_H

#endif //DNC_MULTIPLICATION_H

char* native(char *a, char *b);
char native_helper_1(char a, char b, char c);
char native_helper_2(char a, char b, char c);
int number_of_digits(char *a);
char* err_repairer(char *result, int a, int b);
char* dnc(char *a, char *b);
char* dnc_odd(char *a, char *b);
char* dnc_helper(char *a, char *b);
char sum_helper_1(char a,char b, char c);
char sum_helper_2(char a,char b);
char* main_sum_helper(char *a,char *b);
char* karatsuba(char *a,char *b);
char* karatsuba_odd(char *a,char *b);
char* karatsuba_helper(char *a,char *b);
char difference_helper_1();
char difference_helper_2();
char* main_difference_helper(char *a,char *b);