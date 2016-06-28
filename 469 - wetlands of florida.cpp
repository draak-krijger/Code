#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std ;

char grid[1000][1000] , visit[1000][1000] ;
int m , n , cnt ;

void dfs(int u , int v)
{
    if(u<0 || u>=m || v<0 || v>=n || grid[u][v] == 'L' || visit[u][v] == '1')
        return ;

    visit[u][v] = '1' ;
    cnt++;

    dfs(u,v+1);
    dfs(u,v-1);
    dfs(u+1,v);
    dfs(u+1,v+1);
    dfs(u+1,v-1);
    dfs(u-1,v);
    dfs(u-1,v+1);
    dfs(u-1,v-1);
}

int main()
{
    int i , j , tcase , u , v , len ;
    char cel[200];
    bool check = false , c2 ;

    scanf("%d",&tcase) != EOF;
    getchar();
    getchar();

    while(tcase--)
    {
        m=n=0 ;

        if(check)
            printf("\n");

        check = true ;
        c2 = false ;

        while(gets(grid[m]) && strlen(grid[m])>0)
        {
            if(isalpha(grid[m][0]))
            {
                m++;
                c2 = true ;
            }

            else
            {
                sscanf(grid[m],"%d %d",&u,&v);

                if(c2)
                {
                    n = strlen(grid[0]);
                    n = m;
                }

                c2 = false ;
                cnt = 0 ;
                for(i=0 ; i<=n ; i++)
                    memset(visit[i],'0',sizeof visit[i]);

                dfs(u-1,v-1);
                printf("%d\n",cnt);
            }
        }

    }
    return 0 ;
}
