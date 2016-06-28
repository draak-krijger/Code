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
#define sz 120

using namespace std ;

struct edge
{
    int u , v , w ;
};

vector<edge>graph ;
int n , parent[sz] ;
long long int cost ;

void calculation(int cas);
bool minst(edge p , edge q);
bool maxst(edge p , edge q);
int find_parent(int u);
void set_parent();
void mst();
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

bool minst(edge p , edge q)
{
    return p.w<q.w ;
}

bool maxst(edge p , edge q)
{
    return p.w>q.w;
}

int find_parent(int u)
{
    if(parent[u] == u)
        return u;

    else
        return parent[u] = find_parent(parent[u]);
}

void set_parent()
{
    for(int i=0 ; i<=n ; i++)
        parent[i] = i ;
}

void mst()
{
    cost = 0 ;
    int u , v , cnt = 0 ;
    set_parent();

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u) ;
        v = find_parent(graph[i].v) ;

        if(u != v)
        {
            parent[u] = v ;
            cnt++;
            cost += graph[i].w ;

            if(cnt == n)
                break;
        }
    }
}

void input()
{
    scanf("%d",&n);

    edge p ;
    graph.clear();

    while(scanf("%d %d %d",&p.u,&p.v,&p.w) != EOF)
    {
        if(p.u == 0 && p.v == 0 && p.w == 0)
            break;
        graph.pb(p);
    }
}

void calculation(int cas)
{
    long long int avg = 0 ;

    sort(graph.begin(),graph.end(),minst);
    mst();
    avg = cost ;

    sort(graph.begin(),graph.end(),maxst);
    mst();
    avg += cost;

    printf("Case %d: ",cas);

    if(avg%2 == 0)
        printf("%lld\n",avg/2);

    else
        printf("%lld/2\n",avg);
}
