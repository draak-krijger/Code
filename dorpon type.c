#include <stdio.h>
int main()
{
    int a , b , i , j , k ;
    while(scanf("%d",&a) != EOF)
    {
         b = a/2 ;
        for(i=0 ; i<=a/2 ; i++)
        {
            k=0 ;
            level:
                k++;
            for(j=0 ; j<=b ;j++)
            {
                printf(" ");
            }
            for(j=0 ; j<=i*2 ;j++)
            {
                if(j==0 || j==i*2)
                    printf("*");
               else  if(i==a/2 && j==a/2)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
            if(k==1)
                goto level;
            b--;
        }

        b=0;

        for(i=a/2 ; i>=0 ; i--)
        {
            k=0;
            level2:
                k++;
            for(j=0 ; j<=b ;j++)
            {
                printf(" ");
            }
            for(j=0 ; j<=i*2 ; j++)
            {
                if(j==0 || j==i*2)
                    printf("*");
                else  if(i==a/2 && j==a/2)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
             if(k==1)
            goto level2;
        b++;
        }
    }

    return 0 ;
}

