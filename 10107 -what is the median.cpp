#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std ;

int main()
{
    int a = 0 , b[100000] , i=0 ;

    while(scanf("%d",&b[i]) != EOF)
    {
        i++;
        sort(b,b+i);
        a = i/2 ;

        if(i%2 == 1)
            printf("%d\n",b[a]);

        else
        {
            a = (b[a] + b[a-1])/2 ;
            printf("%d\n",a);
        }
    }
    return 0 ;
}
