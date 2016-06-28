#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std ;

int main()
{
    int tcase , m , n , ans ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%d %d",&m,&n);

        if(n==1)
            ans = m ;

        else if(m==1)
            ans = n ;

        else if(m==2)
        {
            ans = (n/4)*4 ;

            if(n%4 == 1)
                ans += 2 ;

            else if(n%4 > 1)
                ans += 4 ;
        }

        else if(n==2)
        {
            ans = (m/4) * 4 ;

            if(m%4 == 1)
                ans += 2 ;

            else if(m%4 > 1)
                ans += 4 ;
        }

        else
        {
            ans = (m*n + 1)/2 ;
        }

        printf("Case %d: %d\n",cas,ans);
    }
    return 0 ;
}
