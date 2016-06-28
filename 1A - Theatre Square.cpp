#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std ;

int main()
{
    long long m, n , a , b , c ;

    while(scanf("%I64d %I64d %I64d",&m,&n,&a) == 3)
    {
        b = ceil((double)m/(double)a) * ceil((double)n/(double)a) ;
        printf("%I64d\n",b);
    }
    return 0 ;
}
