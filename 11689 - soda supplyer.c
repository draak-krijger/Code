#include <stdio.h>
int main()
{
    int a , b , c , sum ,t , j ;
    while(scanf("%d",&t) != EOF)
    {
        while(t--)
        {
            scanf("%d %d %d",&a ,&b , &c) != EOF ;
            sum = 0 ;
            a = a+b ;
            while(a>=c)
            {
                b = a/c ;
                sum = sum+b ;
                a = a%c + b ;
            }
            printf("%d\n",sum);
        }
    }
    return 0 ;
}

