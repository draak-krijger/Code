#include <iostream>
#include <cstdio>

using namespace std ;

int main()
{
    int tcase , a , f , k , i , j , space ;

    scanf("%d",&tcase);

    while(tcase--)
    {
        scanf("%d %d",&a,&f);

        for(k=1 ; k<=f ; k++)
        {
            for(i=1 ; i<=a ; i++)
            {
                for(j=1 ; j<=i ; j++)
                    printf("%d",i);

                printf("\n");
            }

            for(i=a-1 ; i>0 ; i--)
            {
                for(j=1 ; j<=i ; j++)
                    printf("%d",i);

                printf("\n");
            }

            if(tcase ==0 && (k == f))
                return 0 ;

                printf("\n");
        }
    }
    return  0 ;
}

