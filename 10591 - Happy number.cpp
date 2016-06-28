#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std ;

int main()
{
    long long a , b , sum , cas , tcase , dig ;

    scanf("%lld",&tcase);

    for(cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%lld",&a);
        b = a ;
        sum = 0 ;

        while(1)
        {
            sum = 0 ;

            while(b>0)
            {
                dig = b%10;
                sum += pow((double)dig,2.0);
                b = b/10;
            }

            b = sum ;

            if(b<=9)
            {
                break;
            }
        }

        if(b==1 || b==7)
            printf("Case #%lld: %lld is a Happy number.\n",cas,a);

        else
            printf("Case #%lld: %lld is an Unhappy number.\n",cas,a);
    }
    return 0 ;
}
