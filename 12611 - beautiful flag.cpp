#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int tcase , r , length , lef , rig , hig , k =0 ;
    scanf("%d",&tcase);

    while(tcase--)
    {
        k++;
        scanf("%d",&r);

        length = (100*r)/20 ;
        lef = (45*length)/100 ;
        rig = length - lef ;
        hig = (60*length)/200;

        printf("Case %d:\n",k);
        printf("-%d %d\n%d %d\n%d -%d\n-%d -%d\n",lef,hig,rig,hig,rig,hig,lef,hig);
    }
    return 0 ;
}
