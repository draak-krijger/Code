#include <stdio.h>
int main()
{
    long long  a , b , c , d , e , i , j;
    while(scanf("%lld %lld",&a,&b) != EOF && (a&&b))
    {
        c = a-b ;
        e =d= 1 ;

        if(c>b)
        {
            for(i=c+1, j=1; i<=a; i++,j++)
            {
                e *= i;
                d *= j ;
            }
        }

        else
        {

            for(i=b+1,j=1 ; i<=a ; i++,j++)
            {
                e *= i;
                d *= j ;
            }
        }
        d = e/d ;

        printf("%lld\n",d);
    }
    return 0 ;
}

