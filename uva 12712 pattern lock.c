#include <stdio.h>
#include <math.h>
long long int fact(int a)
{
    long long int i , b = 1;
    for(i=1 ; i<=a ; i++)
    {
        b = b*i ;
    //if(b>10000000000007)
        //b = b %10000000000007;
    }
    return b ;
}
int main()
{
    int t , l , m , n , i , j , k ;
    long long int a , b , c , d ;
    while(scanf("%d",&t) != EOF)
    {
        for(i=0 ; i<t ; i++)
        {
            b = 0;
            scanf("%d %d %d",&l,&m,&n);
            for(j=0 ; j <=(n-m) ; j++)
            {
                a = 1 ;
                for(k=n ; k>j ; k--)
                {
                    a = a*k ;
                    if(a>10000000000007)
                        a = a %10000000000007;
                }
                b = b + a ;
            }
            l = l*l ;
            m = l - n ;
            if(m>n)
            {
                a = 1 ;
                for(j=m+1 ; j<=l ; j++)
                {
                    a = a*j ;
                    if(a>10000000000007)
                        a = a %10000000000007;
                }
                c = a/fact(n);
                if(c>10000000000007)
                    c= c %10000000000007;
            }
            else
            {
                a = 1 ;
                for(j=n+1 ; j<=l ; j++)
                {
                    a = a*j ;
                    if(a>10000000000007)
                        a = a %10000000000007;
                }
                c = a/fact(m);
                if(c>10000000000007)
                    c = c %10000000000007;
            }
            d = c*b;
            printf("%lld\n",d);
        }
    }
    return 0 ;
}

