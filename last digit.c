#include <stdio.h>
#include <math.h>
int powermod(base , exp , mod)
{
    int result;
    if(base<1 || exp<0 || mod < 1)
        return -1 ;
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
    int a , b ,c ;
    while(scanf("%d",&a) != EOF)
    {
        if(a==0)
            break;
        c = a ;
        b = 0 ;
        while(c>0)
        {
            b = b+powermod(c,c,10);
            c--;
        }
        b=b%10;
        printf("%d\n",b);
    }
    return 0 ;
}

