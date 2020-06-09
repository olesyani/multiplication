//
// Created by nikita on 08.06.2020.
//

#ifndef DNC_MULTIPLICATION_H
#define DNC_MULTIPLICATION_H

char* native(char *a, char *b);
char native_helper_1(char a, char b, char c);
char native_helper_2(char a, char b, char c);
char* err_repairer(char *result, int a, int b);
int number_of_digits(char *a);
char* dnc(char *a, char *b);
char* dnc_odd(char *a, char *b);
char* dnc_helper(char *a, char *b);
char sum_helper_1(char a,char b, char c);
char sum_helper_2(char a,char b);
char* main_sum_helper(char *a,char *b);

#endif //DNC_MULTIPLICATION_H
