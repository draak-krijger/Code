#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std ;

int main()
{
    int side[5] , tcase ;
    double b ;

    scanf("%d",&tcase);

    for(int cas = 1 ; cas<=tcase ; cas++)
    {
        scanf("%d %d %d",&side[0],&side[1],&side[2]);
        sort(side , side+3);

        b = sqrt((double)(side[0]*side[0]) + (double)(side[1]*side[1]));

        if( b == side[2])
            printf("Case %d: yes\n",cas);

        else
            printf("Case %d: no\n",cas);
    }
    return 0 ;
}
