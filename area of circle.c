#include <stdio.h>
int main ()
{
    double r,area;
    printf("Enter circle radious: ");
    scanf("%lf",&r);
    area=3.1416*r*r;
    printf("area is :%.2lf",area);
    return 0;
}
