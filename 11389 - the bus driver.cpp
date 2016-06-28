#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std ;

int main()
{
    long long int n , d , r , i , sum , cost;

    while(scanf("%lld %lld %lld",&n,&d,&r) != EOF)
    {
        if( !n && !r && !d )
            return 0 ;

        int morn[n] , even[n] ;
        cost = 0 ;

        for(i=0 ; i<n ; i++)
            scanf("%d",&morn[i]);

        sort(morn , morn+n);

         for(i=0 ; i<n ; i++)
            scanf("%d",&even[i]);

        sort(even , even+n);

        for(i=0 ; i<n ; i++)
        {
            sum = morn[i] + even[n-1-i] ;

            if(sum > d)
                cost += sum -d ;
        }

        cost = cost*r ;

        printf("%lld\n",cost);
    }

    return 0;

}
