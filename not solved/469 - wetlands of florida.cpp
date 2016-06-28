#include <iostream>
#include <cstdio>
#include <cstring>

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
    int i , j , tcase , u , v ;
    char cel[200];
    bool check = false ;

    scanf("%d",&tcase) != EOF;
    getchar();
    getchar();

    while(tcase--)
    {
        m=n=0 ;

        if(check)
            printf("\n");

        check = true ;

        while(gets(grid[m]) && isalpha(grid[m][0]))
        {
            m++;
            memset(grid[m], 0 , sizeof grid[m]);
        }

        if(strlen(grid[m]) == 0)
            continue;

        n = strlen(grid[0]);
        u = grid[m][0] - '0' -1 ;
        v = grid[m][2]- '0' - 1 ;

        while(u>=0 && v>=0)
        {
            for(i=0 ; i<=m ; i++)
                memset(visit , '0' , sizeof visit);

            cnt = 0 ;
            dfs(u,v);

            printf("%d\n",cnt);

            gets(cel);

            if(strlen(cel) == 0)
                break;

            u = cel[0] - '0' - 1;
            v = cel[2] - '0' - 1;
        }
    }
    return 0 ;
}
