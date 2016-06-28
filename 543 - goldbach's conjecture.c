#include <stdio.h>
#include <math.h>
int isprime(int a)
{
    int i , b=1 ;
    if(a==2 || a==1)
        b = 0;
    for(i=2 ; i<= sqrt(a) ; i++)
    {
        if(a%i == 0)
        {
            b = 0;
            break;
        }
    }
    return b ;
}
int main()
{
    int a,i,b,c;
    while (scanf("%d",&a) == 1)
    {
        if(a==0)
            break;
        c = 0;
        for(i=3; i<=a/2 ; i+=2)
        {
            if(isprime(i) == 1)
            {
                b = a-i ;
                if(isprime(b) == 1)
                {
                    c = 1 ;
                    printf("%d = %d + %d\n",a,i,b);
                    break;
                }
            }
        }
        if ( c == 0 )
            printf("Goldbach's conjecture is wrong.\n");
    }
    return 0 ;
}

