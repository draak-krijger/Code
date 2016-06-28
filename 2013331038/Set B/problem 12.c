#include<stdio.h>
int main()
{
    double a,c;
    int b;
    scanf("%lf",&a);
    b=a;
    c=a-b;
    if(c>.4)
        b=b+1;
    printf("%d",b);
    return 0;
}

