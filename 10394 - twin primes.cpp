#include <iostream>
#include <cstdio>
#define jora pair<int,int>

using namespace std ;

int prim[21000000] ;

jora num[110000] ;

void check ()
{
    long long int i , j , k=1 ;

    prim[1] = 1 ;

    for(i=4 ; i<=20000000 ; i = i+2)
        prim[i] = 1 ;

    for(i=3 ; i<=20000000 ; i = i+2)
    {
        if(prim[i] == 0)
        {
            if(prim[i-2] == 0)
            {
                num[k].first = i-2;
                num[k].second = i ;
                k++;//printf("%d\n",i);
            }

            for(j=i+i ; j<=20000000 ; j = j+i)
                prim[j] = 1 ;
        }
    }
}

int main()
{
    long long int s ;
    check();

    while(scanf("%lld",&s)  != EOF)
    {
        printf("(%d, %d)\n",num[s].first , num[s].second);
    }
    return 0 ;
}
