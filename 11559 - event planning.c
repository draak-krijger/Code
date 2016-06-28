#include <stdio.h>

int main()
{
    int a[4] , b , c[3] , d , e , i , j  ;

    while(scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3]) != EOF)
    {

        int cost =a[1]+1000 ;
        for(i=0 ; i<a[2] ; i++)
        {
            scanf("%d",&b);

            for(j=0 ; j<a[3] ; j++)
            {
                scanf("%d",&e);

                if(e>=a[0] ){
                        d = b*a[0] ;
                if(d<cost)
                    cost = d ;
                }
            }
        }

        if(cost<=a[1])
            printf("%d\n",cost);
        else
            printf("stay home\n");
    }
    return 0 ;
}

