#include<stdio.h>
#include <math.h>

int rev(long int a)
{
    int b = a,i = 0 , rim ;
    while(b>0)
    {
        b=b/10;
        i++;
    }
    b=0;
    while(a>0)
    {
        if(a>=10)
        {
            rim=(a%10);
            a =a/10;
            b += rim*pow(10,(i-1));
        }
        else
        {
            b +=a;
            a= a/10 ;
        }
        i--;
    }
    return b;
}
int prime(long int a)
{
    int b = 1 , i ;
    if(a == 1)
        b = 0;
    else if(a>3)
    {
        for(i=2 ; i<=(int)sqrt(a) ; i++)
        {
            if(a%i == 0)
            {
                b=0;
                break;
            }
        }
    }
    return b ;
}

int main()
{
    long int a;
    while(scanf("%ld",&a) == 1)
    {
        if(prime(a) == 0)
            printf ("%ld is not prime.\n", a);
        else if(prime(a) == 1)
        {
            if(rev(a) != a && prime(rev(a)) == 1)
                printf ("%ld is emirp.\n",a);
            else
                printf ("%ld is prime.\n",a);
        }
    }
    return 0 ;
}

