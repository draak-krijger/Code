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
#define sz  110
#define mx 110000

using namespace std ;

struct node
{
    int u ;
    long long int w ;
//    node(int a,int b)
//    {
//        u = a;
//        w = b;
//    }

    bool operator<(const node&p) const
    {
        return w<p.w;
    }
};

vector<int>graph[sz],cost[sz] ;
int n ;
long long int level[sz] ;

void calculation(int cas);
void reset();
void djkastra();
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
        cost[i].clear();
        level[i] = mx ;
    }
}

void djkastra()
{
    priority_queue<node>q ;
    int u , v ;
    node top , get ;

    get.u = 1 ;
    get.w = 0 ;
    q.push(get);
    level[1] = 0 ;

    while(!q.empty())
    {
        top = q.top();
        q.pop();

        for(int i=0 ; i<graph[top.u].size() ; i++)
        {
            v = graph[top.u][i] ;

            if(level[top.u]+cost[top.u][i] <= level[v])
            {
                level[v] = level[top.u] + cost[top.u][i] ;
                get.u = v ;
                get.w = level[v];
                q.push(get);
            }
        }
    }
}

void input()
{
    int m , u , v , w ;

    scanf("%d %d",&n,&m);
    reset();

    for(int i=0 ; i<m ; i++)
    {
        scanf("%d %d %d",&u,&v,&w);

        graph[u].pb(v);
        graph[v].pb(u);
        cost[u].pb(w);
        cost[v].pb(w);
    }
}

void calculation(int cas)
{
    djkastra();

    if(level[n] == mx)
        printf("Case %d: Impossible\n",cas);

    else
        printf("Case %d: %lld\n",cas,level[n]);
}
