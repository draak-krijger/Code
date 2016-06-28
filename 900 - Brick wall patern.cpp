#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int cas , i ;
    long long a[100] ;

    a[1] = 1 ;
    a[2] = 2 ;

    for(i=3 ; i<=50 ; i++)
        a[i] = a[i-1] + a[i-2] ;

    while(scanf("%d",&cas) != EOF )
    {
        if(cas == 0)
            break ;

        printf("%lld\n",a[cas]);
    }
    return 0 ;
}
