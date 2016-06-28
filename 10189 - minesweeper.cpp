#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;
int b[150][150] ;
char a[150][150] ;

int cost (int i , int j)
{
    if(i>0 && j>0)
        b[i-1][j-1]++;

    if(i>0)
    {
        b[i-1][j+1]++;
        b[i-1][j]++;
    }

    if(j>0)
    {
        b[i][j-1]++;
        b[i+1][j-1]++;
    }

    b[i][j+1]++;
    b[i+1][j]++;
    b[i+1][j+1]++;
}

int main()
{
    int m , n , i , j , k=0,inp[150] ;

    while(scanf("%d %d",&m,&n) != EOF)
    {
        if(!m && !n)
            return 0 ;

        for(i=0 ; i<m ; i++)
        {
            memset(b[i],0,sizeof(b[i]));
            scanf("%s",a[i]);
        }

        for(i=0 ; i<m ; i++)
        {
            for(j=0; j<=n ; j++)
            {
                if(a[i][j] == '*')
                    cost(i,j);
            }
        }

        if(k)
            printf("\n");

        printf("Field #%d:\n",++k);

        for(i=0 ; i<m ; i++)
        {
            for(j=0 ; j<n ; j++)
            {
                if(a[i][j] =='*')
                    printf("%c",a[i][j]);

                else
                    printf("%d",b[i][j]);
            }
            printf("\n");
        }
    }
    return 0 ;
}

