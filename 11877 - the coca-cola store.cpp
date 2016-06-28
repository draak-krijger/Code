#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int n , a , sum ;

    while(scanf("%d",&n) != EOF )
    {
        if(!n)
            return 0 ;

        sum = 0 ;
        while(n>=2)
        {
            a = n / 3 ;
            n = n%3 ;
            n = n + a ;
            sum += a ;

            if(n==2)
                n++;
        }
        printf("%d\n",sum);
    }
    return 0 ;
}
