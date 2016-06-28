#include<stdio.h>
int main()
{
    double a;
    int b,c;
    scanf("%lf",&a);
    b=a;
    if((a-b)!=0)
        c=b+1;
    else
        c=b;
    printf("%d %d",b,c);
    return 0;
}

