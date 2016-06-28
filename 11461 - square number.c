#include <stdio.h>
#include <math.h>
int max(long long int a,long long int b)
{
    if(a>b)
        return a;
    else return b;
}
int min(long long int a,long long int b)
{
    if(a<b)
        return a;
    else return b;
}
int main()
{
    long long int a , b , c , d , e , i , j ;
    while(scanf("%lld %lld",&a ,&b) == 2)
    {
        i = 1;
        j = 0;
        if(a == 0 && b == 0)
            break;
        c  = max(a,b) ;
        d = min(a,b) ;
        while(1)
        {
            e = pow(i,2);
            //printf("%lld",e);
            if( e > c )
                break;
            if(e >= d && e <= c)
                  j++;
            i++;
        }
        printf("%lld\n",j);
    }
    return 0;
}

