#include <stdio.h>
#include <math.h>
int main()
{
    double a,b;
    double c;
    while(scanf("%lf %lf",&a,&b) != EOF)
    {
        c=(double)1/a;
        printf("%.0lf\n",pow(b,c));
    }
    return 0;
}
