#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std ;

int main()
{
    int tcase , k , m , i , j , l;
    double sum ;
    char line[100000];

    scanf("%d",&tcase);

    while(tcase--)
    {
        sum = 0 ;
        scanf("%d",&k);
        getchar();

        char crt[k+1];
        int exp[k+1];

        for(i=0 ; i<k ; i++)
        {
            scanf("%c %d",&crt[i],&exp[i]);
            getchar();
        }

        scanf("%d",&m);
        getchar();

        for(i=0 ; i<m ; i++)
        {
            gets(line);

            for(j=0 ; j<strlen(line) ; j++)
            {
                for(l=0 ; l<k ; l++)
                {
                    if(line[j] == crt[l])
                    {
                        sum += (double)exp[l]/100 ;
                        break;
                    }
                }
            }
        }

        printf("%.2lf$\n",sum);
    }
    return 0 ;
}
