#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
#define PB push_back

using namespace std ;

struct node
{
    int u , v , w ;

    bool operator < (const node&p ) const
    {
        return w<p.w ;
    }
};

void reset();
int find_parent(int a);
int mst(int a);

vector <node>graph ;

int parent[10009] , n , cont ;
bool check[10009] ;

int main()
{
    int m , tcase , w , aircost ;
    long long cost ;
    node get ;
//freopen("input.txt","r",stdin);
    scanf("%d",&tcase);

    for(int cas=1 ; cas<=tcase ; cas++)
    {
        scanf("%d %d %d",&n,&m,&aircost);
        reset();

        for(int i=0 ; i<m ; i++)
        {
            scanf("%d %d %d",&get.u, &get.v ,&get.w);
            graph.PB(get);
        }

        for(int i=1; i<=n ; i++)
        {
            parent[i] = i ;
        }

        w = mst(aircost);

        cost = w + aircost*(n-cont) ;

        printf("Case #%d: %lld %d\n",cas,cost,(n-cont));
    }
    return 0 ;
}

int find_parent(int a)
{
    if(parent[a] == a)
        return a ;

    else
        return parent[a] = find_parent(parent[a]);
}

int mst(int a)
{
    sort(graph.begin(),graph.end());

    int u , v , w = 0 ;
    cont = 0 ;

    for(int i=0 ; i<graph.size() ; i++)
    {
        u = find_parent(graph[i].u);
        v = find_parent(graph[i].v);

        if(u!=v)
        {
            parent[u] = v ;

            if(graph[i].w<a)
            {
                cont++;
                w += graph[i].w ;
            }
        }
    }
    return w ;
}

void reset()
{
    graph.clear();
    fill(check , check+10009 , false);
}
