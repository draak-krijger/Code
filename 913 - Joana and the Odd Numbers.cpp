#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    long long sum , a , i ;

    while(scanf("%lld",&a) != EOF)
    {
        sum = ((a*(a+2))/2)*3 - 6 ;

        printf("%lld\n",sum);
    }
    return 0 ;
}

