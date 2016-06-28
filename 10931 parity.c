#include <stdio.h>

int binary(int a)
{
    int b[10000] ;
    int i , j , k ;
    j=0 ;
    i=0 ;
    while(a>=1)
    {
        b[j] = a%2 ;
        j++ ;
        if(a%2 == 1)
            i++ ;
        a = a/2;
    }
     for(k=j-1 ; k>=0 ; k--)
    printf("%d",b[k]);

         return i ;
}

int main()
{
   int a ;
    while(scanf("%d",&a) != EOF)
    {
        if(a==0)
            break ;

        printf("The parity of ");
        a = binary(a);
        printf(" is %d (mod 2).\n",a);
    }
    return 0 ;
}

