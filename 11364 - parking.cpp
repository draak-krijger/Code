#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std ;

int main()
{
    int tcase , n , x[25] , i , diff ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d",&n);

        for(i=0 ; i<n ; i++)
            scanf("%d",&x[i]);

        sort(x , x+n);

        diff = x[n-1] - x[0];
        diff = diff*2 ;

        printf("%d\n",diff);
    }
    return 0 ;
}

