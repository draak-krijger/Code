#include <stdio.h>
#include <math.h>

int prime(int a)
{
    int i,b=1;
    for(i=2; i<=sqrt(a); i++)
    {
        if(a%i== 0)
            b=0;
    }
    if(a==1)
        b=0;
    return b;
}

int main()
{
    int a=1,i=0,sum=0;
    while(a<=1000)
    {
        if(prime(a)==1)
        {
            i++;

            sum=sum+a;
        }
        a++;
    }
    printf("number: %d sum : %d",i,sum);
    return 0;
}

