#include <stdio.h>
#include <math.h>
int main()
{
    double a, b;
    double c, d;

    while(scanf("%lf %lf", &a, &b) == 2)
    {
        c = (double)1 / a;
        d = pow(b, c);
        printf("%.0lf\n", d);
    }

    return 0;
}
