
#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int x1 , x2 , y1 , y2 ;

    while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2) != EOF )
    {
        if(x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
            return 0 ;

        else if(x1 == x2 && y1 == y2)
            printf("0\n");

        else if((x1+y1)==(x2+y2) || x1==x2 || y1==y2 || (x1-y1) == (x2-y2))
            printf("1\n");

        else
            printf("2\n");
    }
    return 0 ;
}
