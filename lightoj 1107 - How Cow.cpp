#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std ;

int main()
{
    int x1 , y1 , x2 , y2 , x , y , tcase , m ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d",&m);

        printf("Case %d:\n",cas);

        for(int i=0 ; i<m ; i++)
        {
            scanf("%d %d",&x,&y);

            if(x>x1 && x<x2 && y>y1 && y<y2)
                printf("Yes\n");

                else
                    printf("No\n");
        }
    }
    return 0 ;
}
