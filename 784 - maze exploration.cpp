#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std ;

char maz[40][100] ;

void dfs(int u , int v )
{
    if(maz[u][v] != '*' && maz[u][v] != '_' && maz[u][v] != ' ')
        return;

    maz[u][v] = '#';

    dfs(u,v+1);
    dfs(u,v-1);
    dfs(u+1,v);
    dfs(u-1,v);
}

int main()
{
    int l , lf , i , j , k , tcase ;

    scanf("%d",&tcase);
    getchar();

    while(tcase--)
    {
        i=lf=0 ;

        while(gets(maz[i]) && maz[i][0] != '_')
        {
            i++;
        }

        for(k=0 ; k<i ; k++)
        {
            for(j=0 ; j<strlen(maz[k]) ; j++)
            {
                if(maz[k][j] == '*')
                    break;
            }

            if(maz[k][j] == '*')
                    break;

        }

        dfs(k,j);

        for(j=0 ; j<=i ; j++)
            puts(maz[j]);

    }
    return 0 ;
}
