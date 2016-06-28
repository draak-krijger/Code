#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

int main()
{
    int tcase , n , a , b ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d",&n);

        a = n/2 ;
        b = n-a ;
        printf("%d %d\n",a,b);
    }
    return 0 ;
}
