#include <stdio.h>
#include <math.h>
int powermod(int base ,int exp ,int mod)
{
    int result;
    if(base<1 || exp<0 || mod < 1)
        return -1 ;
//printf("%d %d %d\n",base,exp,mod);
    result = 1;
    while(exp>0)
    {
        if((exp%2) == 1)
        {
            result = (result * base)%mod;
        }
        base = (base*base)%mod;
        exp = floor(exp/2);
    }
    return result;
}
int main()
{
    int a , b ;
    while(scanf("%d",&a)==1)
    {
        b = powermod(a,1000000007-2,1000000007);
        printf("%d\n",b);
    }
    return 0 ;
}

