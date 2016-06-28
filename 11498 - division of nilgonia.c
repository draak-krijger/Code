#include <stdio.h>
int main()
{
    int t , x , y , h , k , i ;

    while(scanf("%d",&t) != EOF)
    {
        if(t==0)
            break;

        scanf("%d %d",&x,&y);

        for(i=0 ; i<t ; i++)
        {
            scanf("%d %d",&h,&k);

            if(x==h || y==k)
                printf("divisa\n");

            else if(x<h && y<k)
                printf("NE\n");

            else if(x<h && y>k)
                printf("SE\n");

            else if(x>h && y<k)
                printf("NO\n");

            else
                printf("SO\n");
        }
    }
    return 0 ;
}

