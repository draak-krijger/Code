#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std ;

vector<int>graph[100];
int level[50] , visit[50] ;

void  bfs(int v)
{
    int u , i , p ;
    queue<int>q ;

    q.push(v);
    level[v] = 0 ;
    visit[v] = 1 ;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(i=0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i] ;

            if(visit[v] == 1)
                continue;

            visit[v] = 1 ;
            level[v] = level[u] +1 ;
            q.push(v) ;
        }
    }
}

int main()
{
    int edge , cntry , i = 1 , j , k=0 , tcase , start , destination ;
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&edge) != EOF)
    {
        for(j=0 ; j<edge ; j++)
        {
            scanf("%d",&cntry);
            graph[i].push_back(cntry);
            graph[cntry].push_back(i);
        }

        i++;
        if(i<20)
            continue;

        scanf("%d",&tcase);

        printf("Test Set #%d\n",++k);

        for(i=0 ; i<tcase ; i++)
        {
            scanf("%d %d",&start,&destination);

            memset(level, 0 , sizeof level);
            memset(visit , 0 , sizeof visit);

            bfs(start);

            printf("%2d to %2d: %d\n",start,destination,level[destination]);
        }

        printf("\n");

        for(i=0 ; i<=50 ; i++)
            graph[i].clear();

        i=1 ;
    }

    return 0 ;
}
