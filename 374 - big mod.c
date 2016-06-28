#include <stdio.h>
#include <math.h>
int powermod(long long base,long long exponent,long long modulus)
{
    int result ;
    if (base < 0 || exponent < 0 || modulus < 1)
        return 1;
    result = 1;
    while (exponent > 0)
    {
        if ((exponent % 2) == 1)
        {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = floor(exponent / 2);
    }
    return result;
}
int main()
{
    long long int a , b ,c,d;
    while(scanf("%lld %lld %lld",&a,&b,&c) != EOF)
    {
        d = powermod(a,b,c);
        printf("%lld\n",d);
    }
    return 0 ;
}
