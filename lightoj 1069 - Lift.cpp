#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std ;

int main()
{
    int tcase , yourposition , liftposition , a ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%d %d",&yourposition,&liftposition);

        a = abs(liftposition-yourposition) + yourposition ;

        a = a*4 +10+9 ;

        printf("Case %d: %d\n",cas,a);
    }
    return 0 ;
}
