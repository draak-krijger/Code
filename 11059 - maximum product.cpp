#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std ;

int main()
{
    long long int a , ara[50] , cas = 0 , maxmam , pd ;

    while(scanf("%lld",&a) != EOF)
    {
        for(int i=0 ; i<a ; i++)
            scanf("%lld",&ara[i]);

        maxmam = 0 ;

        for(int i=0 ; i<a ; i++)
        {
            pd = ara[i] ;

            if(pd>maxmam)
                    maxmam = pd ;

            for(int j=i+1 ; j<a ; j++)
            {
                pd = pd * ara[j];

                if(pd>maxmam)
                    maxmam = pd ;
            }

            if(pd>maxmam)
                    maxmam = pd ;
        }

        printf("Case #%lld: The maximum product is %lld.\n\n",++cas,maxmam);
    }
    return 0 ;
}
