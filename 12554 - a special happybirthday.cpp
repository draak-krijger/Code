#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std ;

char name[150][150] ;

int main()
{
    int n , gl , i , j , k ;

    while(scanf("%d",&n) != EOF)
    {
        gl = ceil((double)n/16.0);

        for(i=1 ; i<=n ; i++)
            scanf("%s",name[i]);

        k=1;

        for(i=0 ; i<gl ; i++)
        {
            for(j=0 ; j<2 ; j++)
            {
                printf("%s: Happy\n",name[k]);

                if( k== n)
                    k=0 ;

                k++;

                printf("%s: birthday\n",name[k]);

                if( k== n)
                    k=0 ;

                k++;

                printf("%s: to\n",name[k]);

                if( k== n)
                    k=0 ;

                k++;

                printf("%s: you\n",name[k]);

                if( k== n)
                    k=0 ;

                k++;
            }

            for(j=0 ; j<1 ; j++)
            {
                printf("%s: Happy\n",name[k]);

                if( k== n)
                    k=0 ;

                k++;

                printf("%s: birthday\n",name[k]);

                if( k== n)
                    k=0 ;

                k++;

                printf("%s: to\n",name[k]);

                if( k== n)
                    k=0 ;

                k++;

                printf("%s: Rujia\n",name[k]);

                if( k== n)
                    k=0 ;

                k++;
            }

                        for(j=0 ; j<1 ; j++)
            {
                printf("%s: Happy\n",name[k]);

                if( k== n)
                    k=0 ;

                k++;

                printf("%s: birthday\n",name[k]);

                if( k== n)
                    k=0 ;

                k++;

                printf("%s: to\n",name[k]);

                if( k== n)
                    k=0 ;

                k++;

                printf("%s: you\n",name[k]);

                if( k== n)
                    k=0 ;

                k++;
            }
        }
    }
    return 0 ;
}
