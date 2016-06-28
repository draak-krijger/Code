#include <iostream>
#include <cstdio>
#include <cmath>
#define pi acos(-1)

using namespace std ;

int main()
{
    int tcase , n ;
    double R , r ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%lf %d",&R,&n);

        r = (R*sin(pi/n))/(sin(pi/n)+1);
        printf("Case %d: %.6lf\n",cas,r);
    }
    return 0 ;
}
