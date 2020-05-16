#include "mult.h"

void PrintStr(INT_LONG str) {
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

INT_LONG RandString(int size) {
    INT_LONG NUM;
    NUM.data = (char*)malloc(size * sizeof(char));
    for (int i = 0; i < size-1; i++) {
        NUM.data[i] = rand()%10;
    }
    NUM.data[size-1] = rand()%9 + 1;
    NUM.size = size;
    PrintStr(NUM);
    return NUM;
}

//num1 is always bigger than num2
INT_LONG Addition(INT_LONG num1, INT_LONG num2) {
    INT_LONG RES;
    RES.data = (char*)malloc(num1.size * (sizeof(char)));
    RES.size = num1.size;
    char D = 0;
    int i = 0;
    while (i != num2.size) {
        if (num1.data[i] + num2.data[i] + D > 9) {
            RES.data[i] = (num1.data[i] + num2.data[i] + D) % 10;
            D = 1;
        }
        else {
            RES.data[i] = num1.data[i] + num2.data[i] + D;
            D = 0;
        }
        i++;
    }
    while (i != num1.size) {
        if (num1.data[i] + D > 9) {
            RES.data[i] = (num1.data[i] + D) % 10;
            D = 1;
        }
        else {
            RES.data[i] = num1.data[i] + D;
            D = 0;
        }
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

INT_LONG NaiveMULT(INT_LONG num, char n, int pos) {
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
        RES = NaiveMULT(num1, num2.data[i], i);
        if (RES.size > R.size)
            RES = Addition(RES, R);
        else
            RES = Addition(R, RES);
    }
    return RES;
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

INT_LONG SimpleDNC(INT_LONG num1, INT_LONG num2) {
    INT_LONG RES;
    int n;
    if (num1.size > num2.size)
        n = num1.size;
    else
        n = num2.size;
    if ((n <= 1)||(num1.size == 0)||(num2.size == 0)) {
        if ((num1.size == 1)&&(num2.size == 1)) {
            if (num1.data[0] * num2.data[0] > 9) {
                RES.data = (char*)malloc(2 * sizeof(char));
                RES.data[0] = (num1.data[0] * num2.data[0]) % 10;
                RES.data[1] = (num1.data[0] * num2.data[0]) / 10;
                RES.size = 2;
                return RES;
                }
            else {
                RES.data = (char*)malloc(1 * sizeof(char));
                RES.data[0] = num1.data[0] * num2.data[0];
                RES.size = 1;
                return RES;
            }
        }
        else {
            RES.data = (char*)malloc(1 * sizeof(char));
            RES.data[0] = 0;
            RES.size = 0;
            return RES;
        }
    }
    else {
        INT_LONG xR, xL, yR, yL;
        xR = Divide(num1, 0, n/2);
        xL = Divide(num1, n/2, n);
        yR = Divide(num2, 0, n/2);
        yL = Divide(num2, n/2, n);
        INT_LONG x1 = SimpleDNC(xL, yL);
        INT_LONG x2 = SimpleDNC(xL, yR);
        INT_LONG x3 = SimpleDNC(xR, yL);
        INT_LONG x4 = SimpleDNC(xR, yR);
        x1 = NaiveMULT(x1, 1, 2*(n/2));
        if (x2.size > x3.size)
            x2 = Addition(x2, x3);
        else
            x2 = Addition(x3, x2);
        x2 = NaiveMULT(x2, 1, n/2);
        if (x1.size > x2.size)
            x1 = Addition(x1, x2);
        else
            x1 = Addition(x2, x1);
        if (x1.size > x4.size)
            x1 = Addition(x1, x4);
        else
            x1 = Addition(x4, x1);
        RES = x1;
        return RES;
    }
}

INT_LONG KaratsubaDNC(INT_LONG num1, INT_LONG num2) {
    INT_LONG RES;
    int n;
    if (num1.size > num2.size)
        n = num1.size;
    else
        n = num2.size;
    if ((n <= 1)||(num1.size == 0)||(num2.size == 0)) {
        if ((num1.size == 1)&&(num2.size == 1)) {
            if (num1.data[0] * num2.data[0] > 9) {
                RES.data = (char*)malloc(2 * sizeof(char));
                RES.data[0] = (num1.data[0] * num2.data[0]) % 10;
                RES.data[1] = (num1.data[0] * num2.data[0]) / 10;
                RES.size = 2;
                return RES;
                }
            else {
                RES.data = (char*)malloc(1 * sizeof(char));
                RES.data[0] = num1.data[0] * num2.data[0];
                RES.size = 1;
                return RES;
            }
        }
        else {
            RES.data = (char*)malloc(1 * sizeof(char));
            RES.data[0] = 0;
            RES.size = 0;
            return RES;
        }
    }
    else {
        INT_LONG xR, xL, yR, yL;
        xR = Divide(num1, 0, n/2);
        xL = Divide(num1, n/2, n);
        yR = Divide(num2, 0, n/2);
        yL = Divide(num2, n/2, n);
        INT_LONG x1 = SimpleDNC(xL, yL);
        INT_LONG x2;
        if (xL.size > xR.size) {
            if (yL.size > yR.size) {
                x2 = SimpleDNC(Addition(xL, xR), Addition(yL, yR));
            }
            else
                x2 = SimpleDNC(Addition(xL, xR), Addition(yR, yL));
        }
        else {
            if (yL.size > yR.size) {
                x2 = SimpleDNC(Addition(xR, xL), Addition(yL, yR));
            }
            else
                x2 = SimpleDNC(Addition(xR, xL), Addition(yR, yL));
        }
        INT_LONG x3 = SimpleDNC(xR, yR);
        RES = NaiveMULT(x1, 1, 2*(n/2)); //res 1500
        if (RES.size > x3.size)
            RES = Addition(RES, x3); //res 1548
        else
            RES = Addition(x3, RES);
        if (x1.size > x3.size)
            x3 = Addition(x1, x3);
        else
            x3 = Addition(x3, x1); //x3 = 63
        int size2 = x2.size;
        int size3 = x3.size;
        if (x2.size == x3.size) {
            int k = 0;
            while ((size2 == size3)&&(k != x2.size)) {
                if (x2.data[size2 - k] > x3.data[size3 - k]) {
                    size2++;
                }
                else if (x2.data[size2 - k] < x3.data[size3 - k]) {
                    size3++;
                }
                else
                    k++;
            }
        }
        if (size2 > size3) {
            x2 = Subtraction(x2, x3); //58
            x2 = NaiveMULT(x2, 1, n/2); //580
            if (RES.size > x2.size)
                RES = Addition(RES, x2);
            else
                RES = Addition(x2, RES);
        }
        else if (size3 > size2) {
            x2 = Subtraction(x3, x2);
            x2 = NaiveMULT(x2, 1, n/2);
            RES = Subtraction(RES, x2);
        }
        return RES;
    }
}

INT_LONG Grid(INT_LONG num1, INT_LONG num2) {
    char MATRIX[num1.size][num2.size];
    for (int i = 0; i < num1.size; i++) {
        for (int j = 0; j < num2.size; j++) {
            MATRIX[i][j] = num1.data[i] * num2.data[j];
        }
    }
    //char DIAGONAL_SUM[num1.size + num2.size - 1];
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
