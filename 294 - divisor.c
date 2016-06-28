#include <stdio.h>
#include <math.h>

long long int divisor(long long int a)
{
    long long int i , j , k ,numberOfDivisors=2;
    if(a == 1)
        numberOfDivisors=1;
    j=(int)sqrt((double)a);
    for(i=2; i<=j; i++)
        if(a%i==0)
        {
            if(i!=a/i)
                numberOfDivisors+=2;
            else
                numberOfDivisors++;
        }
    return numberOfDivisors ;
}

int main()
{
    long long int a1,a2,a , b , c , d , e , i , k ,t;
    scanf("%lld ",&t) ;
    while(t>0)
    {
        scanf("%lld %lld",&a,&b) != EOF ;
        a1 = a ;
        a2 = b ;
        if(a>b)
        {
            i = b ;
            b =a ;
            a=i ;
        }
        if(a==1 && b==0)
        {
            printf("Between 1 and 1, 0 has a maximum of 2 divisors.\n");
            t--;
            continue ;
        }
        c = 0 ;
        for(i=a ; i<=b ; i++)
        {
            e = divisor(i) ;
            if(e > c)
            {
                c =e ;
                d = i ;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a1,a2,d,c);
        t--;
    }
    return 0 ;
}

