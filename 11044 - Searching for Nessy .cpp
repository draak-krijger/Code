#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int a ,  b , tcase ;

    while(scanf("%d",&tcase) != EOF)
    {
        while(tcase--)
        {
            scanf("%d %d",&a,&b) ;
            printf("%d\n",(a/3)*(b/3));
        }
    }
    return 0 ;
}

