#include <iostream>
#include <cstdio>

using namespace std ;

int m;
char graph[120][120] ;

void dfs(int u , int v)
{
    if(u<0 || u>= m || v<0 || v>= m || graph[u][v] == '0')
        return ;

    graph[u][v] = '0' ;

    dfs(u-1,v-1);
    dfs(u-1,v+1);
    dfs(u-1,v);
    dfs(u,v+1);
    dfs(u,v-1);
    dfs(u+1,v);
    dfs(u+1,v-1);
    dfs(u+1,v+1);
}

int main()
{
    int i , j , cnt , k=0;

    while(scanf("%d",&m) != EOF)
    {
        for(i=0 ; i<m ; i++)
            scanf("%s",graph[i]);

        cnt = 0 ;

        for(i=0 ; i<m ; i++)
        {
            for(j=0 ; j<m ; j++)
            {
                if(graph[i][j] == '1')
                {
                    cnt++ ;
                    dfs(i,j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",++k,cnt);
    }
    return 0 ;
}
