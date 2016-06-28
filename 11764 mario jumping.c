#include <stdio.h>

int main()
{
    int t , i , j , l , h , jump;

    while(scanf("%d",&t) != EOF)
    {

        for(j=0 ; j<t ;j++)
        {

            scanf("%d",&jump);

            int jumpheight[jump];
            l=h=0 ;

            for(i=0 ; i<jump ;i++)
                scanf("%d",&jumpheight[i]);

            for(i=0 ; i< jump-1 ; i++)
            {
                if((jumpheight[i+1]-jumpheight[i])<0)
                    l++;

                 if((jumpheight[i+1]-jumpheight[i])>0)
                    h++ ;
            }

            printf("Case %d: %d %d\n",j+1,h,l);

        }
    }

    return 0;
}

