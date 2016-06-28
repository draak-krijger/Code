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
#define MAX 40000
#define PB push_back

using namespace std ;

vector<int>graph[MAX] , cost[MAX] ;
bool check[MAX] ;
long long int dist ,level[MAX] ;
int n , fu ;

void vreset();
void calculation(int cas);
void breset();
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
    return 0 ;
}

void vreset()
{
    for(int i=0 ; i<=n ; i++)
    {
        graph[i].clear();
        cost[i].clear();
    }
}

void breset()
{
    for(int i = 0 ; i<=n ; i++)
    {
        check[i] = false;
        level[i] = 0 ;
    }
}

void bfs(int src)
{
    breset();
    queue<int>q ;
    int u , v ;

    q.push(src);
    level[src] = 0 ;
    check[src] = true;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(int i=0 ; i<graph[u].size() ; i++)
        {
            v = graph[u][i] ;

            if(check[v])
                continue;

            check[v] = true;
            level[v] = level[u] + cost[u][i] ;
            q.push(v);

            if(level[v]>dist)
            {
                dist = level[v];
                fu = v ;
            }
        }
    }
}

void input()
{
    int u , v , w ;

    scanf("%d",&n);
    vreset();

    for(int i=1 ; i<n ; i++)
    {
        scanf("%d %d %d",&u,&v,&w);

        graph[u].PB(v);
        graph[v].PB(u);
        cost[u].PB(w);
        cost[v].PB(w);
    }
}

void calculation(int cas)
{
    dist = 0 ;

    bfs(0);

    dist = 0 ;
    bfs(fu);

    printf("Case %d: %lld\n",cas,dist);
}
