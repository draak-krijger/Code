// Sieve
#include <stdio.h>
int ara[10000000];
int main()
{
    int a[100000] , i, j , k , b;
    scanf("%d",&b);
    a[0] = 2 ;
    k=1 ;
    for(j=2 ; j<b ; j=2+j)
    {
        ara[j]=1;
    }
    for(i=3 ; i<b ; i=i+2)
    {
        if(ara[i] == 0)
        {
            a[k] = i ;
            for(j=i+i ; j<b ; j=i+j)
            {
                ara[j]=1;
            }
            k++ ;
        }
    }
    for(i=0 ; i<k ; i++)
        printf("%d ",a[i]);
}

