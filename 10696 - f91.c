
#include <stdio.h>
int ds(long long int a)
{
    if(a >= 101)
        return a-10;
    if(a <= 100)
        return ds(ds(a+11));
}
int main()
{
    long long int a , b ;
    while(scanf("%lld",&a))
    {
        if(a==0)
            break;
        b = ds(a);
        printf("f91(%lld) = %lld\n",a,b);
    }
    return 0;
}
