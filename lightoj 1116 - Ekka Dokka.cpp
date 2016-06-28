#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    unsigned long long w , n , m , i ;
    bool check ;
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%llu",&w);

        if(w&1)
            printf("Case %d: Impossible\n",cas);

        else
        {
            m = 1 ;

            while(w%2 == 0)
            {
                m = m*2 ;
                w = w/2 ;
            }

            printf("Case %d: %llu %llu\n",cas,w,m);
        }
    }
    return 0 ;
}
