#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std ;

int main()
{
    int tcase ;
    long long int n , p , a , c , r ;

    scanf("%d",&tcase);

    for(int cas = 1 ; cas<=tcase ; cas++)
    {
        scanf("%lld",&a);

        p = ceil(sqrt((double)a));

        n = p*(p -1) + 1 ;

        if(p&1)
        {
            if(n>a)
            {
                c = p ;
                r = a - (p-1)*(p-1);
            }

            else if(n<a)
            {
                r = p ;
                c = (p*p) - a + 1 ;
            }

            else
                r = c = p ;
        }

        else
        {
            if(n>a)
            {
                r = p ;
                c = a - (p-1)*(p-1) ;
            }

            else if(n<a)
            {
                c = p ;
                r = p*p - a + 1 ;
            }

            else
                c = r = p ;
        }

        printf("Case %d: %lld %lld\n",cas,c,r);
    }
    return 0 ;
}
