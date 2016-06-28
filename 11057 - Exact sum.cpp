#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std ;

int main()
{
    int t , money , x , y , diff , fd , i , j ;

    while(scanf("%d",&t) != EOF)
    {
        int b[t+10];
        fd = 100000000 ;

        for(i=0 ; i<t ; i++)
            scanf("%d",&b[i]);

        scanf("%d",&money);

        sort(b , b+t);

        for(i=0 ; i<t-1 ; i++)
        {
            for(j=i ; j<t ; j++)
            {
                if(b[i]+b[j] == money)
                {
                    diff = b[j]-b[i];

                    if(diff<fd)
                    {
                        x=b[i];
                        y=b[j];
                    }
                }

                if(b[i] + b[j] >= money)
                    break;
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n",x,y);
    }
    return 0 ;
}

