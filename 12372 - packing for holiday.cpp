#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a , b , c , tcase , i = 0;

    scanf("%d",&tcase);

    while(tcase--)
    {
        i++;
        scanf("%d %d %d",&a,&b,&c);

        if(a>20 || b>20 || c>20)
            printf("Case %d: bad\n",i);

        else
            printf("Case %d: good\n",i);
    }
    return 0;
}
