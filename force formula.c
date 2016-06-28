#include <stdio.h>
int main ()
{
    double q1,q2,d,f;
    printf("q1 is: ");
    scanf("%lf",&q1);
    printf("q2 is: ");
    scanf("%lf",&q2);
    printf("d is: ");
    scanf("%lf",&d);
    f=(9*1000000000*q1*q2)/(d*2);
    printf("f is:%lf",f);
    return 0;
}
