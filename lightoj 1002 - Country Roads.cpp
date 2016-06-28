#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include <climits>
#define jora pair<int,int>
#define pb push_back
#define sz 510
#define Max 30000

using namespace std ;

vector<int>graph[sz],cost[sz] ;
int level[sz] , n , m , t ;

void calculation(int cas);
void reset();
void bfs(int src);
void input();

int main()
{
    int tcase ;

    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        input();
        calculation(cas);
    }
    return 0;
}

void reset()
{
    for(int i=0 ; i<=n ; i++)
    {
        graph[i].clear();
        level[i] = Max ;
        cost[i].clear();
    }
}

void bfs(int src)
{
    queue<int>q ;
    int u , v ;

    q.push(src);
    level[src] = 0 ;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i=0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i];
            if(max(level[u],cost[u][i])<level[v])
            {
                level[v] = max(level[u],cost[u][i]);
                q.push(v);
            }
        }
    }
}

void input()
{
    scanf("%d %d",&n,&m);
    reset();

    int u , v , w ;

    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d %d",&u,&v,&w);

        graph[u].pb(v);
        graph[v].pb(u);
        cost[u].pb(w);
        cost[v].pb(w);
    }
    scanf("%d",&t);
}

void calculation(int cas)
{
    bfs(t);

    printf("Case %d:\n",cas);

    for(int i=0 ; i<n ; i++)
    {
        if(level[i] == Max)
            printf("Impossible\n");

        else
            printf("%d\n",level[i]);
    }
}
