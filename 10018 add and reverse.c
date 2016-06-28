#include <stdio.h>
long long int reverse(long long int a)
{
    long long int b=0;
    while(a != 0)
    {
        b = b*10;
        b = b + a%10;
        a = a/10;
    }
    return b;
}
int main()
{
    int j , c ;
    long long int a , b , i ;
    scanf("%d",&c) != EOF ;
    for(j=0 ; j<c ; j++)
    {
        scanf("%lld",&a) != EOF ;
        i=0;
        while(1)
        {
            i++;
            b = reverse(a);
            a = a + b ;
             if(a == reverse(a))
                break;
        }
        printf("%lld %lld\n",i,a);
    }
    return 0 ;
}

