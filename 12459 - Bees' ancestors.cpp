#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int a , i ;
    long long b[100] ;
    b[1]=1;
    b[2]=2;

    for(i=3 ; i<=80 ; i++)
    {
        b[i] = b[i-1] + b[i-2];
    }

    while(scanf("%d",&a) != EOF)
    {
        if(a==0)
            return 0 ;

        printf("%lld\n",b[a]);
    }

    return  0;
}
