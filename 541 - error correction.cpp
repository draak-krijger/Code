#include <iostream>
#include <cstdio>

using namespace std ;

int matrix[100][100] , m , r1 , c1 , r , c , sum ;

int row()
{
    int i , j ;
    r1 = 0 ;

    for(i=1 ; i<=m ; i++)
    {
        sum = 0 ;
        for(j=1 ; j<=m ; j++)
        {
            sum += matrix[i][j] ;
        }
        if(sum & 1)
        {
            r1++;
            r = i ;
        }
    }
}

int clm()
{
    int i , j ;
    c1 = 0 ;

    for(i=m ; i>0 ; i--)
    {
        sum = 0 ;

        for(j=1 ; j<=m ; j++)
        {
            sum += matrix[j][i];
        }

        if(sum & 1)
        {
            c1++;
            c = i ;
        }
    }
}

int main()
{
    int i , j ;

    while(scanf("%d",&m) != EOF)
    {
        if(!m)
            return 0 ;

        for(i=1 ; i<=m ; i++)
        {
            for(j=1 ; j<=m ; j++)
            {
                scanf("%d",&matrix[i][j]);
            }
        }

        row();
        clm();

        if(c1 == 0 && r1 == 0)
            printf("OK\n");

        else if(c1 == 1 && r1 == 1)
            printf("Change bit (%d,%d)\n",r,c);

        else
            printf("Corrupt\n");
    }
    return 0 ;
}
