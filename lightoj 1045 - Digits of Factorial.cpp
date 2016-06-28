#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1000000

using namespace std ;

void calculationdigit();

double digit[MAX+7] ;

int main()
{
    int tcase , n , base ;
    long long result ;

    scanf("%d",&tcase);
    calculationdigit();

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%d %d",&n,&base);

        result = digit[n] / log10((double)base);

        result = result + 1;
        printf("Case %d: %lld\n",cas,result);
    }

    return 0 ;
}

void calculationdigit()
{
    digit[1] = 0 ;

    for(int i=2 ; i<=MAX ; i++)
        digit[i] = digit[i-1] + log10(i) ;
}
