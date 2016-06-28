#include <iostream>
#include <cstdio>

using namespace std ;

char graph[110][110];
int m , n ;

void dfs(int u , int v)
{
    if(u<0 || u>=m || v<0 || v>=n || graph[u][v] == '*')
        return;

    graph[u][v] = '*' ;

    dfs(u-1,v-1);
    dfs(u-1,v+1);
    dfs(u-1,v);
    dfs(u,v-1);
    dfs(u+1,v-1);
    dfs(u,v+1);
    dfs(u+1,v);
    dfs(u+1,v+1);
}

int main()
{
    int i , j , cnt ;

    while(scanf("%d %d",&m,&n) != EOF)
    {
        if(m==0)
            return 0 ;

        for(i=0 ; i<m ; i++)
            scanf("%s",graph[i]);

        cnt = 0 ;

        for(i=0 ; i<m ; i++)
        {
            for(j=0 ; j<n ; j++)
            {
                if(graph[i][j] == '@')
                {
                    cnt++;
                    dfs(i,j);
                }
            }
        }

        printf("%d\n",cnt);

    }
    return 0 ;
}
