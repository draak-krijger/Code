#include <cstdio>
#include <iostream>
#include <cmath>
#define pi acos(-1)

using namespace std ;

int main()
{
    double a , b ;
    double c ;

    while(cin >> a >> b)
    {

        c = .5 * b * a * a * sin((360*pi)/(180*b)) ;

        printf("%.3lf\n",c);

    }

    return 0 ;
}

