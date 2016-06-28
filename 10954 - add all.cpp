#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std ;

int main()
{
    int n , i ;
    long long int sum , l ;
    while(scanf("%d",&n) != EOF)
    {
        if(!n)
            return 0;

        long long int num[n+5];

        for(i=0 ; i<n ; i++)
            scanf("%lld",&num[i]);

        sort(num , num+n , greater<int>());

        sum = 0 ;

        while(n>1)
        {
            l = num[n-1] + num[n-2];
            sum += l ;
            num[n-2] = l ;
            sort(num , num+n , greater<int>());
            n--;
        }
        printf("%lld\n",sum);
    }
    return 0 ;
}
