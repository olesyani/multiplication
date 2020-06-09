//
// Created by nikita on 08.06.2020.
//

#include <stdlib.h>
#include <f2fs_fs.h>
#include "multiplication.h"

char* native(char *a, char *b) {
    int num1 = number_of_digits(a), num2 = number_of_digits(b);
    char *result = (char *) calloc(num1 + num2 + 1, sizeof(char));
    int counter = 0;
    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++) {
            result[counter] = native_helper_1(a[i], b[j], result[counter]);
            result[counter + 1] = native_helper_2(a[i], b[j], result[counter + 1]);
            result = err_repairer(result, num1, num2);
            counter++;
        }
        counter = counter - num2 + 1;
    }
    if (result[0] == 48) {
        for (int i = 0; i < num1 + num2 + 1; i++) {
            result[i] = result[i + 1];
        }
    }
    return result;
}

char native_helper_1(char a, char b, char e) {
    int d = (a - 48) * (b - 48);
    if (e == 0) {
        if (d >= 10) {
            return d / 10 + 48;
        } else {
            return 48;
        }
    } else {
        if (d >= 10) {
            return d / 10 + e;
        } else {
            return e;
        }
    }
}

char native_helper_2(char a, char b, char e) {
    int d = (a - 48) * (b - 48);
    if (e == 0) {
        if (d >= 10) {
            return d % 10 + 48;
        } else {
            return d + 48;
        }
    } else {
        if (d >= 10) {
            return d % 10 + e;
        } else {
            return d + e;
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

int number_of_digits(char *a) {
    int num = 0;
    while(a[num]!=0) {
        num++;
    }
    return num;
}

char* dnc(char *a, char *b) {
    int num1 = number_of_digits(a), num2 = number_of_digits(b);
    if((num1==1)&&(num2==1)) {
        char *result = (char *) calloc(num1+num2+1,sizeof(char));
        result = native(a,b);
        return result;
    } else if((num1%2==1)||(num2%2==1)) {
        char *result = (char *) calloc(num1+num2+1,sizeof(char));
        result = dnc_odd(a,b);
        return result;
    } else {
        char *result = (char *) calloc(num1+num2+1,sizeof(char));
        result = dnc_helper(a,b);
        return result;
    }
}

char* dnc_odd(char *a, char *b) {
    int num1 = number_of_digits(a), num2 = number_of_digits(b);
    if((num1%2==1)&&(num2%2==1)) {
        a[num1] = '0';
        b[num2] = '0';
        char *result = (char *) calloc(num1+num2+1,sizeof(char));
        result = dnc_helper(a,b);
        int numres = number_of_digits(result);
        a[num1] = 0;
        b[num2] = 0;
        result[numres-1] = 0;
        result[numres-2] = 0;
        return result;
    } else if(num1%2==1) {
        a[num1] = '0';
        char *result = (char *) calloc(num1+num2+1,sizeof(char));
        result = dnc_helper(a,b);
        int numres = number_of_digits(result);
        a[num1] = 0;
        result[numres-1] = 0;
        return result;
    } else if(num2%2==1) {
        b[num2] = '0';
        char *result = (char *) calloc(num1+num2+1,sizeof(char));
        result = dnc_helper(a,b);
        int numres = number_of_digits(result);
        b[num2] = 0;
        result[numres-1] = 0;
        return result;
    }
}

char* dnc_helper(char *a, char *b) {
    int num1 = number_of_digits(a), num2 = number_of_digits(b),counter = 0;
    if(num1>num2) {
        for(int i = num2;i<num1;i++) {
            b[i] = '0';
            counter++;
        }
    } else if(num2>num1) {
        for(int i = num1;i<num2;i++) {
            a[i] = '0';
            counter++;
        }
    }
    num1 = number_of_digits(a),num2 = number_of_digits(b);
    char *al = (char *) calloc(num1/2+1,sizeof(char));
    char *ar = (char *) calloc(num1/2+1,sizeof(char));
    char *bl = (char *) calloc(num2/2+1,sizeof(char));
    char *br = (char *) calloc(num2/2+1,sizeof(char));
    int temp = 0;
    for(int i = 0;i<num1/2;i++) {
        al[i] = a[i];
    }
    for(int i = num1/2;i<num1;i++) {
        ar[temp] = a[i];
        temp++;
    }
    temp = 0;
    for(int i = 0;i<num2/2;i++) {
        bl[i] = b[i];
    }
    for(int i = num2/2;i<num2;i++) {
        br[temp] = b[i];
        temp++;
    }
    char *x1 = (char *) calloc(num1/2+num2/2+1,sizeof(char));
    char *x2 = (char *) calloc(num1/2+num2/2+1,sizeof(char));
    char *x3 = (char *) calloc(num1/2+num2/2+1,sizeof(char));
    char *x4 = (char *) calloc(num1/2+num2/2+1,sizeof(char));
    x1 = dnc(al,bl);
    x2 = dnc(al,br);
    x3 = dnc(ar,bl);
    x4 = dnc(ar,br);
    int numx1 = number_of_digits(x1);
    int numx2 = number_of_digits(x2);
    int numx3 = number_of_digits(x3);
    char *x1new = (char*)calloc(numx1+max(num1,num2)+1,sizeof(char));
    for(int i = 0;i<numx1;i++) {
        x1new[i] = x1[i];
    }
    for(int i = numx1;i<numx1+max(num1,num2);i++) {
        x1new[i] = '0';
    }
    char *sum = (char*)calloc(max(numx2,numx3)+max(num1,num2)/2+2,sizeof(char));
    sum = main_sum_helper(x2,x3);
    int numsum = number_of_digits(sum);
    for(int i = numsum;i<numsum+max(num1,num2)/2;i++) {
        sum[i] = '0';
    }
    numsum = number_of_digits(sum);
    int numx1new = number_of_digits(x1new);
    char *intermediate_result = (char*)calloc(max(numx1new,numsum)+2,sizeof(char));
    intermediate_result = main_sum_helper(x1new,sum);
    char *result = (char *) calloc(num1 + num2 + 1, sizeof(char));
    result = main_sum_helper(intermediate_result,x4);
    int numres = number_of_digits(result);
    while(result[0]=='0') {
        for(int i = 0;i<numres;i++) {
            result[i] = result[i+1];
        }
    }
    if(result[0]==0) {
        result[0] = '0';
    }
    for(int i = 0;i<num1+num2;i++) {
        err_repairer(result,num1,num2);
    }
    if(counter==0) {
        return result;
    } else {
        for(int i = numres-counter;i<numres;i++) {
            result[i] = 0;
        }
        return result;
    }
}

char sum_helper_1(char a, char b, char e) {
    int d = (a - 48) + (b - 48);
    if (e == 0) {
        if (d >= 10) {
            return d / 10 + 48;
        } else {
            return 48;
        }
    } else {
        if (d >= 10) {
            return d / 10 + e;
        } else {
            return e;
        }
    }
}

char sum_helper_2(char a, char b) {
    int d = (a - 48) + (b - 48);
    if (d >= 10) {
        return d % 10 + 48;
    } else {
        return d + 48;
    }
}

char* main_sum_helper(char *a,char *b) {
    int num1 = number_of_digits(a), num2 = number_of_digits(b);
    char *sum = (char*)calloc(max(num1,num2)+2,sizeof(char));
    if(num1!=num2) {
        int difference = max(num1,num2) - min(num1,num2);
        if(num1>num2) {
            for(int i = 0;i<difference;i++) {
                sum[i] = a[i];
            }
            for(int i = difference;i<num1;i++) {
                sum[i-1] = sum_helper_1(a[i],b[i-difference],sum[i-1]);
                sum[i] = sum_helper_2(a[i],b[i-difference]);
            }
        } else {
            for(int i = 0;i<difference;i++) {
                sum[i] = b[i];
            }
            for(int i = difference;i<num2;i++) {
                sum[i-1] = sum_helper_1(a[i-difference],b[i],sum[i-1]);
                sum[i] = sum_helper_2(a[i-difference],b[i]);
            }
        }
        return sum;
    } else {
        for(int i = 0;i<max(num1,num2);i++) {
            sum[i] = sum_helper_1(a[i],b[i],sum[i]);
            sum[i+1] = sum_helper_2(a[i],b[i]);
        }
        return sum;
    }
}