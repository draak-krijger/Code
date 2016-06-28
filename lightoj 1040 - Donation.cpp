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
#define sz 60

using namespace std ;

struct node
{
    int u , v , w ;
};

vector<node>graph ;
int n , parent[sz] ;
long long int cost ;

void calculation(int cas);
int find_par(int p);
void set_par();
bool cmp(node p , node q);
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

int find_par(int p)
{
    if(parent[p] == p)
        return p ;

    else
        return parent[p] = find_par(parent[p]);
}

void set_par()
{
    for(int i=0 ; i<=n ; i++)
        parent[i] = i;
}

bool cmp(node p , node q)
{
    return p.w < q.w;
}

void mst()
{
    int u , v , cnt = 0 ;
    cost = 0 ;
    set_par();

    for(int i=0 ; i<graph.size(); i++)
    {
        u = find_par(graph[i].u);
        v = find_par(graph[i].v);

        if(u != v)
        {
            parent[u] = v;
            cnt++;
        }

        else
            cost += graph[i].w ;
    }

    if(cnt != n-1)
        cost = -1 ;
}

void input()
{
    scanf("%d",&n);
    int w ;
    node get ;
    graph.clear();

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=1 ; j<=n ; j++)
        {
            scanf("%d",&w);

            if(w>0)
            {
                get.u = i ;
                get.v = j ;
                get.w = w ;
                graph.pb(get);
            }
        }
    }
}

void calculation(int cas)
{
    sort(graph.begin(),graph.end(),cmp);
    mst();

    printf("Case %d: %lld\n",cas,cost);
}
