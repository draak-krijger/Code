#include <stdio.h>
int main()
{
    long long a ;
    int t , i ;
    while(scanf("%d",&t) != EOF)
    {
        for(i=0 ; i<t ; i++)
        {
            scanf("%lld",&a) != EOF ;
            a = (((((((a*567)/9)+7492)*235)/47) - 498) /10)%10 ;
            if(a<0)
                a = a * (-1) ;
            printf("%lld\n",a);
        }
    }
    return 0 ;
}

