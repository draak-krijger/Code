#include <stdio.h>
int main()
{
    int a , b , c , d , i , j=0 , k ;
    while(scanf("%d",&a) != EOF)
    {
        if(a == 0)
        {
            printf("END OF OUTPUT\n");
            break;
        }
        j++;
        if( j ==1)
            printf("PERFECTION OUTPUT\n");
        b = 1 ;
        c = a ;
        for(i=2 ; i<c ; i++)
        {
            if(a%i == 0)
            {
                c = a/i ;
                if( i != c )
                b = b+i+c;
            }
        }
        if(a == 1)
            printf("%5d  DEFICIENT\n",a);
        else if(a == b)
            printf("%5d  PERFECT\n",a);
        else if(b<a)
            printf("%5d  DEFICIENT\n",a);
        else if(b>a)
            printf("%5d  ABUNDANT\n",a);
    }
    return 0;
}

