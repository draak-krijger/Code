#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define pi 2*acos(0.0)

using namespace std ;

int main()
{
    int tcase ;
    double r , area , a ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%lf",&r);
        a = r*2.0 ;
        area = (a*a) - (pi*r*r) ;
        printf("Case %d: %.2lf\n",cas,area);
    }
    return 0 ;
}
