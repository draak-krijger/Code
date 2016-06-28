#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define PB push_back

using namespace std ;

struct node
{
    int u , w ;

    bool operator < (const node&p) const
    {
        return w >= p.w ;
    }
};
void reset();
vector<int>graph[100] ;
vector<int>cost[100] ;
vector<int>line ;
int level[100] , parent[100];

int djkastra(int n)
{
    int u , v ;
    memset(level , 10000 , sizeof level);
    priority_queue < node > q ;
    node get ;
    get.u = 1 ;
    get.w = 0 ;
    q.push(get);
    level[1] = 0 ;

    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        u = top.u;

        if(u==n)
            return level[u] ;

        for(int i=0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i] ;

            if(level[u] + cost[u][i] <= level[v])
            {
                level[v] = level[u] + cost[u][i] ;
                parent[v] = u ;
                get.u = v ;
                get.w = level[v];
                q.push(get);
            }
        }
    }
    return -1 ;
}
int main()
{
    int u , v , w , n , e ;

    while(scanf("%d %d",&n,&e) == 2)
    {
        reset();

        for(int i=0 ; i<e ; i++)
        {
            scanf("%d %d %d",&u,&v,&w);

            graph[u].PB(v);
            graph[v].PB(u);
            cost[u].PB(w);
            cost[v].PB(w);
        }

        w = djkastra(n);

        printf("minimum cost : %d\npath:\n",w);
        e = n ;
        while(1)
        {
            line.PB(e);

            if(e==1)
                break;
            e = parent[e] ;
        }
        reverse(line.begin(),line.end());
        for(int i=0 ; i<line.size() ; i++)
            printf("%d ",line[i]);
        cout<<endl;
    }
    return 0 ;
}

void reset()
{
    for(int i=0 ; i<=100 ; i++)
        graph[i].clear();
    line.clear();
}

