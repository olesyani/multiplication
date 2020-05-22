#include "mult.h"

void PrintString(INT_LONG str) {
    int i = str.size;
    while (i != 0) {
        i--;
        printf("%d", str.data[i]);
    }
    puts("");
}

void Clean(INT_LONG num) {
    if (num.size > 0) {
        for (int i = num.size - 1; i <= 0; i++) {
            free(num.data[i]);
        }
        free(num.data);
    }
}

char IsBigger(INT_LONG num1, INT_LONG num2) {
    int size1 = num1.size;
    int size2 = num2.size;
    if (size1 == size2) {
        int K = size1;
        while ((num1.data[K] == num2.data[K])&&(K != 0))
            K--;
        if (num1.data[K] > num2.data[K])
            return 1;
        else if (num2.data[K] > num1.data[K])
            return 2;
        else
            return 0;
    }
    else if (size1 > size2)
        return 1;
    else
        return 2;
}

INT_LONG RandString(int size) {
    INT_LONG NUM;
    NUM.data = (char*)malloc(size * sizeof(char));
    for (int i = 0; i < size-1; i++) {
        NUM.data[i] = rand()%10;
    }
    NUM.data[size-1] = rand()%9 + 1;
    NUM.size = size;
    PrintString(NUM);
    return NUM;
}

INT_LONG Addition(INT_LONG num1, INT_LONG num2) {
    INT_LONG RES;
    RES.data = (char*)malloc(num1.size * (sizeof(char)));
    RES.size = num1.size;
    char D = 0;
    int i = 0;
    while (i != num2.size) {
        char a = num1.data[i] + num2.data[i] + D;
        RES.data[i] = a % 10;
        D = a / 10;
        i++;
    }
    while (i != num1.size) {
        char a = num1.data[i] + D;
        RES.data[i] = a % 10;
        D = a / 10;
        i++;
    }
    if (D != 0) {
        RES.data[i] = (char)malloc(1 * sizeof(char));
        RES.data[i] = D;
        RES.size += 1;
    }
    else {
        i--;
        while ((RES.data[i] == 0)&&(RES.size != 0)) {
            free(RES.data[i]);
            RES.size -= 1;
            i--;
        }
    } 
    return RES;
}

INT_LONG Subtraction(INT_LONG num1, INT_LONG num2) {
    INT_LONG RES;
    RES.data = (char*)malloc(num1.size * (sizeof(char)));
    RES.size = num1.size;
    char D = 0;
    int i = 0;
    while (i != num2.size) {
        if (num1.data[i] - num2.data[i] - D < 0) {
            RES.data[i] = num1.data[i] - num2.data[i] - D + 10;
            D = 1;
        }
        else {
            RES.data[i] = num1.data[i] - num2.data[i] - D;
            D = 0;
        }
        i++;
    }
    while (i != num1.size) {
        if (num1.data[i] - D < 0) {
            RES.data[i] = num1.data[i] + D + 10;
            D = 1;
        }
        else {
            RES.data[i] = num1.data[i] - D;
            D = 0;
        }
        i++;
    }
    i--;
    while ((RES.data[i] == 0)&&(RES.size != 0)) {
        free(RES.data[i]);
        RES.size -= 1;
        i--;
    }
    return RES;
}

INT_LONG NaiveMultiplication(INT_LONG num, char n, int pos) {
    INT_LONG RES;
    RES.data = (char*)malloc(((num.size) + pos) * (sizeof(char)));
    RES.size = (num.size) + pos;
    int i = pos;
    char D = 0;
    if (num.size == 0) {
        RES.data = (char*)malloc(1 * sizeof(char));
        RES.data[0] = 0;
        RES.size = 0;
        return RES;
    }
    for (int j = 0; j < pos; j++) {
        RES.data[j] = 0;
    }
    for (int j = 0; j < num.size; j++) {
        if (num.data[j] * n + D > 9) {
            RES.data[i] = (num.data[j] * n + D) % 10;
            D = (num.data[j] * n + D) / 10;
        }
        else {
            RES.data[i] = num.data[j] * n + D;
            D = 0;
        }
        i++;
    }
    if (D != 0) {
        RES.data[i] = (char)malloc(1 * sizeof(char));
        RES.data[i] = D;
        RES.size += 1;
    }
    return RES;
}

INT_LONG Naive(INT_LONG num1, INT_LONG num2) {
    INT_LONG RES;
    RES.size = 0;
    for (int i = 0; i < num2.size; i++) {
        INT_LONG R = RES;
        RES = NaiveMultiplication(num1, num2.data[i], i);
        if (RES.size > R.size)
            RES = Addition(RES, R);
        else
            RES = Addition(R, RES);
    }
    return RES;
}

INT_LONG Grid(INT_LONG num1, INT_LONG num2) {
    char MATRIX[num1.size][num2.size];
    for (int i = 0; i < num1.size; i++) {
        for (int j = 0; j < num2.size; j++) {
            MATRIX[i][j] = num1.data[i] * num2.data[j];
        }
    }
    INT_LONG DIAGONAL_SUM;
    DIAGONAL_SUM.data = (char*)malloc((num1.size + num2.size - 1) * sizeof(char));
    DIAGONAL_SUM.size = num1.size + num2.size - 1;
    long int previous = 0;
    int n = 0;
    for (int i = 0; i < num1.size; i++) {
        int k = i;
        long int add = 0;
        for (int j = 0; j < num2.size && k >= 0; j++, k--) {
            add += MATRIX[k][j];
        }
        add += previous;
        previous = add / 10;
        add = add % 10;
        DIAGONAL_SUM.data[n] = add;
        n++;
    }
    for (int k = 1; k < num2.size; k++) {
        int i = num1.size - 1;
        int j = k;
        int add = 0;
        while (j < num2.size && i >= 0) {
            add += MATRIX[i][j];
            j++;
            i--;
        }
        add += previous;
        previous = add / 10;
        add = add % 10;
        DIAGONAL_SUM.data[n] = add;
        n++;
    }
    if (previous > 0) {
        DIAGONAL_SUM.data[n] = (char)malloc(1 * sizeof(char));
        DIAGONAL_SUM.data[n] = previous;
        DIAGONAL_SUM.size += 1;
    }
    return DIAGONAL_SUM;
}

INT_LONG Divide(INT_LONG num, int first, int last) {
    INT_LONG res;
    res.size = 0;
    if (first < num.size) {
        int i = 0;
        res.data = (char*)malloc((last - first) * sizeof(char));
        while ((first != last)&&(first < num.size)) {
            res.data[i] = num.data[first];
            res.size += 1;
            first++;
            i++;
        }
        return res;
    }
    else
        return res;
}

INT_LONG MakeEqual(INT_LONG num1, INT_LONG num2) {
    for (int i = num2.size; i < num1.size; i++) {
        num2.data[i] = (char)malloc(1 * sizeof(char));
        num2.data[i] = 0;
        num2.size += 1;
    }
    return num2;
}

INT_LONG ExtraDigits(INT_LONG num, int n) {
    INT_LONG RESULT;
    RESULT.data = (char *)malloc((num.size + n) * sizeof(char));
    for (int i = 0; i < n; i++) {
        RESULT.data[i] = 0;
    }
    for (int i = n; i < n + num.size; i++) {
        RESULT.data[i] = num.data[i - n];
    }
    RESULT.size = n + num.size;
    return RESULT;
}

INT_LONG SimpleDNC(INT_LONG num1, INT_LONG num2) {
    INT_LONG RESULT;
    RESULT.data = (char*)malloc(1 * sizeof(char));
    RESULT.data[0] = 0;
    RESULT.size = 0;
    if (num1.size > num2.size)
        num2 = MakeEqual(num1, num2);
    else if (num2.size > num1.size)
        num1 = MakeEqual(num2, num1);
    int n = num1.size;
    int N = floor(n/2);
    if (n == 0)
        return RESULT;
    if (n == 1) {
        char a = num1.data[0] * num2.data[0];
        RESULT.data[0] = a % 10;
        RESULT.size = 1;
        if (a / 10 > 0) {
            RESULT.data[1] = (char)malloc(1 * sizeof(char));
            RESULT.data[1] = a / 10;
            RESULT.size = 2;
        }
        return RESULT;
    }
    else {
        INT_LONG xR, xL, yR, yL;
        xR = Divide(num1, 0, N);
        xL = Divide(num1, N, n);
        yR = Divide(num2, 0, N);
        yL = Divide(num2, N, n);
        INT_LONG x1 = SimpleDNC(xL, yL);
        INT_LONG x2 = SimpleDNC(xL, yR);
        INT_LONG x3 = SimpleDNC(xR, yL);
        INT_LONG x4 = SimpleDNC(xR, yR);
        x1 = ExtraDigits(x1, 2 * N);
        if (x2.size > x3.size)
            x2 = Addition(x2, x3);
        else
            x2 = Addition(x3, x2);
        x2 = ExtraDigits(x2, N);
        if (x1.size > x2.size)
            x1 = Addition(x1, x2);
        else
            x1 = Addition(x2, x1);
        if (x1.size > x4.size)
            x1 = Addition(x1, x4);
        else
            x1 = Addition(x4, x1);
        RESULT = x1;
        return RESULT;
    }
}

INT_LONG Karatsuba(INT_LONG num1, INT_LONG num2) {
    INT_LONG RESULT;
    RESULT.data = (char*)malloc(1 * sizeof(char));
    RESULT.data[0] = 0;
    RESULT.size = 0;
    if (num1.size > num2.size)
        num2 = MakeEqual(num1, num2);
    else if (num2.size > num1.size)
        num1 = MakeEqual(num2, num1);
    int n = num1.size;
    int N = floor(n/2);
    if (n == 0)
        return RESULT;
    if (n == 1) {
        char a = num1.data[0] * num2.data[0];
        RESULT.data[0] = a % 10;
        RESULT.size = 1;
        if (a / 10 > 0) {
            RESULT.data[1] = (char)malloc(1 * sizeof(char));
            RESULT.data[1] = a / 10;
            RESULT.size = 2;
        }
        return RESULT;
    }
    INT_LONG xR, xL, yR, yL;
    xR = Divide(num1, 0, N);
    xL = Divide(num1, N, n);
    yR = Divide(num2, 0, N);
    yL = Divide(num2, N, n);
    INT_LONG X1, X2, X3;
    X1.size = 0;
    X2.size = 0;
    X3.size = 0;
    X1 = Karatsuba(xL, yL);
    X2 = Karatsuba(xR, yR);
    if (xR.size > xL.size)
        xR = Addition(xR, xL);
    else
        xR = Addition(xL, xR);
    if (yR.size > yL.size)
        yR = Addition(yR, yL);
    else
        yR = Addition(yL, yR);
    X3 = Karatsuba(xR, yR);
                                    //x1 * 10^n
    RESULT = ExtraDigits(X1, N * 2);
                                    //x1 + x2
    if (X1.size > X2.size)
        X1 = Addition(X1, X2);
    else
        X1 = Addition(X2, X1);
                                    //x1 * 10^n + x2
    if (RESULT.size > X2.size)
        RESULT = Addition(RESULT, X2);
    else
        RESULT = Addition(X2, RESULT);
                                    //if x3 > (x1 + x2) ->  addititing all parts after a subtraction
                                    //if x3 < (x1 + x2) ->  doing x1 * 10^n + x2 - ((x1 + x2) - x3)
    if (IsBigger(X3, X1) == 1) {
        X3 = Subtraction(X3, X1);
        X3 = ExtraDigits(X3, N);
        if (RESULT.size > X3.size)
            RESULT = Addition(RESULT, X3);
        else
            RESULT = Addition(X3, RESULT);
    }
    else if (IsBigger(X3, X1) == 2) {
        X3 = Subtraction(X1, X3);
        X3 = ExtraDigits(X3, N);
        RESULT = Subtraction(RESULT, X3);
    }
    return RESULT;
}
