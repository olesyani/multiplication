//
// Created by Nikita on 18.05.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "multiplication.h"

char* native(char *a, char *b) {
    int num1 = number_of_digits(a), num2 = number_of_digits(b);
    char *result = (char *) malloc((num1 + num2 + 1) * sizeof(char));
    int counter = 0;
    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++) {
            result[counter] = native_helper_1(a[i], b[j], result[counter]);
            result[counter + 1] = native_helper_2(a[i], b[j], result[counter + 1]);
            counter++;
        }
        counter = counter - num2 + 1;
    }
    if (result[0] == 48) {
        for (int i = 0; i < num1 + num2 + 1; i++) {
            result[i] = result[i + 1];
        }
    }
    for (int i = 0; i < num1 + num2 - 3; i++) {
        result = err_repairer(result, num1, num2);
    }
    return result;
}

char native_helper_1(char a, char b, char c) {
    int d = (a - 48) * (b - 48);
    if (c == 0) {
        if (d > 10) {
            return d / 10 + 48;
        } else {
            return 48;
        }
    } else {
        if (d > 10) {
            return d / 10 + c;
        } else {
            return c;
        }
    }
}

char native_helper_2(char a, char b, char c) {
    int d = (a - 48) * (b - 48);
    if (c == 0) {
        if (d > 10) {
            return d % 10 + 48;
        } else {
            return d + 48;
        }
    } else {
        if (d > 10) {
            return d % 10 + c;
        } else {
            return d + c;
        }
    }
}

int number_of_digits(char *a) {
    for (int i = 0; i < 256; i++) {
        if (a[i] == '\0') {
            return i;
        } else {
            continue;
        }
    }
}

char* err_repairer(char *result, int a, int b) {
    for (int i = 0; i < a + b; i++) {
        if (result[i] > 57) {
            result[i - 1] = result[i - 1] + (result[i] - 48) / 10;
            result[i] = (result[i] - 48) % 10 + 48;
        }
    }
    return result;
}

char* dnc(char *a, char *b) {
    int num1 = number_of_digits(a), num2 = number_of_digits(b);
    if((num1==1)&&(num2==1)) {
        char *result = (char*)malloc((num1+num2+1)*sizeof(char));
        result = native(a,b);
        return result;
    } else if((num1%2==1)||(num2%2==1)) {
        char *result = (char*)malloc((num1+num2+1)*sizeof(char));
        return result;
    } else {
        char *result = (char*)malloc((num1+num2+1)*sizeof(char));
        result = dnc_helper(a,b);
        return result;
    }
}

char* dnc_helper(char *a, char *b) {
    int num1 = number_of_digits(a), num2 = number_of_digits(b);
    char *al = (char*)malloc((num1/2+1)*sizeof(char));
    char *ar = (char*)malloc((num1/2+1)*sizeof(char));
    char *br = (char*)malloc((num2/2+1)*sizeof(char));
    char *bl = (char*)malloc((num2/2+1)*sizeof(char));
    int temp = 0;
    for(int i = 0;i < num1/2; i++) {
        al[i] = a[i];
    }
    for(int i = num1/2;i<num1;i++) {
        ar[temp] = a[i];
    }
    temp = 0;
    for(int i = 0; i < num2/2; i++) {
        bl[i] = b[i];
    }
    for(int i = num2/2; i<num2;i++) {
        br[temp] = b[i];
    }
    char *x1 = (char*)malloc((number_of_digits(al)+number_of_digits(bl)+1)*sizeof(char));
    char *x2 = (char*)malloc((number_of_digits(al)+number_of_digits(br)+1)*sizeof(char));
    char *x3 = (char*)malloc((number_of_digits(ar)+number_of_digits(bl)+1)*sizeof(char));
    char *x4 = (char*)malloc((number_of_digits(ar)+number_of_digits(br)+1)*sizeof(char));
    x1 = native(al,bl);
    x2 = native(al,br);
    x3 = native(ar,bl);
    x4 = native(ar,br);
    int numx1 = number_of_digits(x1);
    int numx2 = number_of_digits(x2);
    int numx3 = number_of_digits(x3);
    char *x1new = (char*)malloc((num2+num1+1)*sizeof(char));
    for(int i = 0;i<numx1;i++) {
        x1new[i] = x1[i];
    }
    for(int i = numx1;i<numx1+num1;i++) {
        x1new[i] = '0';
    }
    char *sum = (char*)malloc((numx2+numx3+1)*sizeof(char));//тут начинаются косяки, хотя я перешел на c11
    for(int i = 0;i<numx2+numx3;i++) {//теперь вроде можно юзать функцию макс и это должно решить этот и еще
        sum[i] = sum_helper_1(x2[i],x3[i],sum[i]);//пару траблов чуть выше
        sum[i+1] = sum_helper_2(x2[i],x3[i]);
    }
    return 0;
}

char sum_helper_1(char a, char b, char c) {
    int d = (a - 48) + (b - 48);
    if (c == 0) {
        if (d > 10) {
            return d / 10 + 48;
        } else {
            return 48;
        }
    } else {
        if (d > 10) {
            return d / 10 + c;
        } else {
            return c;
        }
    }
}

char sum_helper_2(char a, char b) {
    int d = (a - 48) + (b - 48);
    if (d > 10) {
        return d % 10 + 48;
    } else {
        return d + 48;
    }
}