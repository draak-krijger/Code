#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std ;

int main()
{
    long long int n ;

    while(scanf("%lld",&n) != EOF)
    {
        if(n==0)
            break;

        if(ceil(sqrt(n)) == floor(sqrt(n)))
            printf("yes\n");

        else
            printf("no\n");
    }
    return 0 ;
}
