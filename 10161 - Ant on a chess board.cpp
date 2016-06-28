#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std ;

int main()
{
    long long int n , p , a , c , r ;

    while(scanf("%lld",&a) != EOF)
    {
        if(a==0)
            return 0 ;

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

        printf("%lld %lld\n",c,r);

    }
    return 0 ;
}
