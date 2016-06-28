#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std ;

int main()
{
    double b ;
    int i , j , k , l , n , r ;

    while(scanf("%d %d",&n,&r))
    {

        if(n==0 && r==0)
            return 0 ;

        l = n-r ;
        if(l>r)
        {
            b = 1 ;
            for(i=l+1 , j=1; i<=n ; i++,j++)
            {
                b = b*((double)i/(double)j);
            }
        }

        else
        {
            b = 1 ;

            for(i=r+1,j=1 ; i<=n ; i++,j++ )
                b = b*((double)i/(double)j);
        }
        printf("%d things taken %d at a time is %.0lf exactly.\n",n,r,b);
    }
    return 0 ;
}
