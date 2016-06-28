#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long testc ,  div , cas , i , cnt;

    while(scanf("%lld %lld",&testc , &div) != EOF)
    {
        cnt=0 ;

        for(i=0 ; i<testc ; i++)
        {
            scanf("%lld",&cas) != EOF;

            if(cas%div == 0)
                cnt++ ;
        }

        printf("%lld\n",cnt);
    }

    return 0;
}

