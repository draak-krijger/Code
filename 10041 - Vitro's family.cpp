#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std ;

int main()
{
    int tcase , r , i , j , sum , mnm ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d",&r);

        int street[r+5];

        for(i=0 ; i<r ; i++)
            scanf("%d",&street[i]);

        sort(street , street+r);
        mnm = 30000000 ;

        for(i=0 ; i<r ; i++)
        {
            sum = 0 ;
            for(j=0 ; j<r ; j++)
                sum += abs(street[i]-street[j]);

            mnm = min(mnm,sum);
        }
        printf("%d\n",mnm);
    }
    return 0 ;
}
