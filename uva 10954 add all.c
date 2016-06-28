#include <stdio.h>
int sort (int a[] , int b)
{
    int i , j , t ;
    for(i=0 ;i<b-1 ; i++)
    {
        for(j=0 ; j<b-i-1 ; j++)
        {
            if(a[j] > a[j+1])
            {
                t = a[j];
                a[j] = a[j+1];
                a[j+1] = t ;
            }
        }
    }
}
int main()
{
    int i , j ;
    long a ;
    while(scanf("%ld",&a) != EOF)
    {
        if(a==0)
            break ;
        int b[a],c[a];
        for(i=0 ; i<a ; i++)
        {
            scanf("%d",&b[i]);
        }
        sort(b,a);
        long long d ;
        c[0] = b[0] + b[1];
        d = c[0];
        for(i=0,j=2 ; j<a ;i++,j++)
        {
            c[i+1] = c[i] + b[j];
            d += c[i+1];
        }
        printf("%lld\n",d);
    }
    return 0 ;
}
