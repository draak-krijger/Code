#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std ;

int cnt;
vector <int> graph[150];
bool visit[150];

void bfs(int v)
{
    int u , i ;
    queue<int>r ;

    r.push(v);

    while(!r.empty())
    {
        v = r.front();
        r.pop();

        for(i=0 ; i<graph[v].size() ; i++)
        {
            u = graph[v][i];

            if(visit[u])
                continue;

            visit[u] = true;
            r.push(u);
        }
    }
}

int main()
{
    int n , a , i , tcase , m , j ;

    while(scanf("%d",&n))
    {
        if(n==0)
        break;

        for( i = 0; i<102; i++ )
            graph[i].clear();

        while(scanf("%d",&a))
        {
            if(a==0)
                break;

            while(scanf("%d",&i) && i != 0)
            {
                if(i==0)
                    break;

                graph[a].push_back(i);
            }
        }

        scanf("%d",&tcase);

        for(i=0 ; i<tcase ; i++)
        {
            memset(visit , false , sizeof visit);

            scanf("%d",&m);

            cnt = 0 ;
            bfs(m);

            for(j=1 ; j<=n ; j++)
            {
                if(!visit[j])
                    cnt++;
            }

            printf("%d",cnt);

            for(j=1 ; j<=n ; j++)
            {
                if(!visit[j])
                    printf(" %d",j);
            }

            printf("\n");
        }
    }
    return 0 ;
}
