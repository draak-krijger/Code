#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iterator>

#define pv push_back

using namespace std ;

vector<int>graph[150];
set<int>nodes;
map<int,int>matrix ;
bool visit[150] ;
int level[150] , cas = 0 , src , ttl , cnt ;
void resetgraph();
void reset();
void bfs(int v);
void pt(int a );

int main()
{
    int tcase , strt , dest , nd ;
//    freopen("input.txt","r",stdin);
    while(scanf("%d",&tcase) == 1)
    {
        if(tcase == 0)
            return 0 ;

        resetgraph();
        nd = 1 ;

        while(tcase--)
        {
            scanf("%d %d",&strt , &dest);

            if(!matrix[strt]) matrix[strt] = nd++;
            if(!matrix[dest]) matrix[dest] = nd++;

            nodes.insert(matrix[strt] );
            nodes.insert(matrix[dest]);

            graph[matrix[strt] ].pv(matrix[dest]);
            graph[matrix[dest]].pv(matrix[strt] );
        }

        while(scanf("%d %d",&src,&ttl) == 2)
        {
            if(src == 0 && ttl == 0)
                break;

            reset();
            bfs(matrix[src]);
            pt(matrix[src]);
        }
    }
    return 0 ;
}

void resetgraph()
{
    matrix.clear();
    nodes.clear();

    for(int i = 0 ; i<= 100 ; i++)
        graph[i].clear();
}

void reset()
{
    cnt = 0 ;
    fill(visit,visit+100,true);
    memset(level , 0 , sizeof level);
}

void bfs(int v)
{
    int u ;
    queue<int>q ;

    q.push(v);
    visit[v] = false ;
    level[v] = 0 ;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i = 0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i];

            if(visit[v])
            {
                level[v] = level[u] + 1;
                visit[v] = false ;
                q.push(v);
            }
        }
    }
}

void pt(int a )
{
    long long l , c ;
    cas++;
    cnt = 0 ;

    for(typeof(nodes.begin()) i = nodes.begin() ; i != nodes.end() ; i++)
    {
        l = *i ;

        if((level[l]>ttl || level[l]<1) && l != a)
        {
            cnt++;
        }
    }
    printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cas,cnt,src,ttl);
}
