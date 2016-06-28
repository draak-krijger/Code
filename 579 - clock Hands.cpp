#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    double a , b ;
    char l ;
    double c , d ;

    while(scanf("%lf %c %lf",&a,&l,&b) != EOF)
    {
        if(a==0 && b==0)
            break;

        a = (a*5) + (b/12);
        //b = 60;

        if(a==60)
            a=0 ;

        a = fabs(a-b);
        a = a*6 ;

        if(a>180)
            a = fabs(360-a);

        printf("%.3lf\n",a);
    }
    return 0 ;
}


