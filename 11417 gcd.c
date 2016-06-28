#include <stdio.h>
int gcd(int a , int b)
{
    int c;
    while(a!=0)
    {
        c=b%a;
        b=a;
        a=c;
    }
    return(b);
}

int main()
{
    int a , b , i , j ;

    while(scanf("%d",&a))
    {
        b=0 ;

        if(a==0)
            break ;

        for(i=1 ; i<a ; i++)
        {
            for(j=i+1 ; j<=a ; j++)
            {
                b += gcd(i,j);
            }
        }

        printf("%d\n",b);
    }
    return 0 ;
}
