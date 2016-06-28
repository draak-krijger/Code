
#include <stdio.h>
#include <math.h>
long long int mx[100000000];
long long int ara[100000000];
int isprime(long long int a )
{
    long long int b , i , j ;
    if(a==7 || a==5 || a==3 || a == 2)
        return 0 ;
        if(a%2 == 0)
            return 1 ;
    if(a==1)
        return 1 ;
     b = sqrt(a);
    for(i=3 ; i<=b ; i += 2)
    {
        if(a%i == 0)
        {
            return 1 ;
        }
    }
    return 0 ;
}
int main()
{
    long long int a,b,c,i , j , k=1 ;
    ara[0] = 2 ;
    a=46341;
    for(i=4 ; i <= a ; i+=2)
        mx[i] = 1 ;
    for(i=3 ; i <= a ; i+=2)
    {
        if(mx[i] == 0)
        {
            ara[k] = i ;
            for(j=i +i; j <= a ; j+=i)
                mx[j] = 1 ;
            k++ ;
        }
    }
    while(scanf("%lld",&a) != EOF)
    {
        if(a == 0)
            break ;
        if(a<0)
        {
            printf("%lld = -1 x ",a);
            a = a*(-1);
        }
        else
            printf("%lld = ",a);
        for(i=0 ; i<k ;)
        {

            if(a%ara[i] == 0)
            {
                printf("%lld",ara[i]);
                a = a/ara[i];
                if(a==1)
                    break ;
                else
                    printf(" x ");
            }
            else
                i++ ;
        }
        if(isprime(a) == 0)
            {
                printf("%lld",a);
            }
        printf("\n");
    }
    return 0 ;
}
