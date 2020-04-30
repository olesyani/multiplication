//
// Created by Nikita on 03.04.2020.
//

#include "multiplication.h"
#include <math.h>

int native(int a,int b)
{
    int c = a*b;
    return c;
}
int dnc(int a,int b)
{
    if((a/10==0)||(b/10==0))
    {
        return a*b;
    } else{
        int n = 0;
        if(a>b)
        {
            int temp = a;
            while(temp/10>0)
            {
                temp = temp/10;
                n++;
            }
        } else{
            int temp = b;
            while(temp/10>0)
            {
                temp = temp/10;
                n++;
            }
        }
        n++;
        int ar,al,br,bl;
        al = a/(int)pow(10,n/2);
        ar = a%(int)pow(10,n/2);
        bl = b/(int)pow(10,n/2);
        br = b%(int)pow(10,n/2);
        int x1 = al*bl,x2 = al*br,x3 = ar*bl,x4 = ar*br;
        return x1*(int)pow(10,n)+(x2+x3)*(int)pow(10,n/2)+x4;
    }
}
int karatsuba(int A,int B)
{
    int i = 0,j = 0;
    float temp1 = (float)A,temp2 = (float)B;
    while(temp1>1)
    {
        temp1 = temp1/10;
        i++;
    }
    while(temp2>1)
    {
        temp2 = temp2/10;
        j++;
    }
    if(i!=j)
    {
        return 0;
    }
    i--;
    int AB,a = A/(int)pow(10,i),b = A%(int)pow(10,i),c = B/(int)pow(10,i),d = B%(int)pow(10,i),x = (int)pow(10,i);
    AB = a*c*x*x+((a+b)*(c+d)-a*c-b*d)*x+b*d;
    return AB;
}