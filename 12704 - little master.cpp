#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std ;

int maxm(int a , int b)
{
    if(a>b)
        return a ;

    else
        return b ;
}

int minm(int a , int b)
{
    if(a<b)
        return a ;

    else
        return b;
}

int main()
{
    int a , b , r , tcase , m , n ;
    double c , d ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d %d %d",&a,&b,&r);

        c = r + sqrt(a*a + b*b);
        d = 2*r - c ;

        printf("%.2lf %.2lf\n",d,c);

    }
    return 0 ;
}
