#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int w ;

    while(scanf("%d",&w) == 1)
    {
        if(w==2)
        {
            printf("NO\n");
            continue;
        }

        if(w & 1)
            printf("NO\n");

        else
            printf("YES\n");
    }
    return 0 ;
}
