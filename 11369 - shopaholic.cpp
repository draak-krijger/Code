#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std ;

int main()
{
    int tcase , number , price[30000] , i , j ;
    long long discount ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d",&number);

        for(i=0 ; i<number ; i++)
            scanf("%d",&price[i]);

        sort(price , price+number , greater<int>());

        discount = 0 ;
        i = 3 ;

        while(i<=number)
        {
            discount += price[i-1];
            i = i+3 ;
        }

        printf("%lld\n",discount);
    }
    return 0 ;
}
