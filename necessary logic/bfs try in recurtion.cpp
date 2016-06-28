#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std ;

vector<int>graph[100];
int n , parent[100] , visited[100] , level[100] , u ;
void bfs(int v)
{
    if(visited[v])
        return ;

    visited[v] = 1 ;

    for(int i =0 ; i<graph[v].size() ; i++)
    {
        u = graph[v][i] ;

        if(visited[u])
            continue;

        level[u] = level[v] + 1 ;
        parent[u] = v ;
        bfs(u);
    }
}

int main()
{
    int i , j , e , x , y ;
    scanf("%d",&n);
    scanf("%d",&e);

    for(i=0 ; i<e ; i++)
    {
        scanf("%d %d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    while(scanf("%d",&e))
    {
        memset(visited , 0 , sizeof visited);
        level[e] = 0 ;

        bfs(e);

         for(i=1; i<=n; i++)
        printf("%d to %d distance %d parent : %d\n",e,i,level[i],parent[i]);

        scanf("%d",&x);
        printf("path : ") ;
        y = x;
        printf("%d",y);
        while(y!=e)
        {
            printf("%d",parent[y]);
            y = parent[y];
        }
        printf("\n");
    }

    return 0 ;
}
